/**
 * @file bench_reporter.cpp
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Catch2 reporter for the TinyUC benchmark tables.
 */

#include "bench_reporter.h"

#include <catch2/benchmark/catch_clock.hpp>
#include <catch2/catch_test_case_info.hpp>
#include <catch2/interfaces/catch_interfaces_reporter.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include <catch2/reporters/catch_reporter_streaming_base.hpp>

#include <cmath>

#include <algorithm>
#include <cstddef>
#include <exception>
#include <fstream>
#include <iomanip>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace {

std::string g_bench_info;

struct sample_stats
{
    double mean = 0.0;
    double median = 0.0;
    double standard_deviation = 0.0;
};

struct benchmark_row
{
    std::string name;
    std::vector<double> samples;
    std::size_t sample_count = 0;
    int iterations = 0;
};

struct benchmark_suite
{
    std::string name;
    std::vector<benchmark_row> rows;
};

std::string format_value(double value, const char* unit)
{
    int precision = 3;
    if (value >= 100.0)
        precision = 1;
    else if (value >= 10.0)
        precision = 2;

    std::ostringstream output;
    output << std::fixed << std::setprecision(precision) << value << ' ' << unit;
    return output.str();
}

std::string format_time(double nanoseconds)
{
    if (nanoseconds >= 1000000000.0)
        return format_value(nanoseconds / 1000000000.0, "s");
    if (nanoseconds >= 1000000.0)
        return format_value(nanoseconds / 1000000.0, "ms");
    if (nanoseconds >= 1000.0)
        return format_value(nanoseconds / 1000.0, "us");
    return format_value(nanoseconds, "ns");
}

std::string format_rate(double calls_per_second)
{
    if (calls_per_second >= 1000000000.0)
        return format_value(calls_per_second / 1000000000.0, "G/s");
    if (calls_per_second >= 1000000.0)
        return format_value(calls_per_second / 1000000.0, "M/s");
    if (calls_per_second >= 1000.0)
        return format_value(calls_per_second / 1000.0, "k/s");
    return format_value(calls_per_second, "/s");
}

std::string format_percent(double value)
{
    std::ostringstream output;
    output << value;
    return output.str();
}

template <typename T>
std::string format_set(const std::set<T>& values)
{
    if (values.empty())
        return "0";
    if (values.size() == 1)
        return std::to_string(*values.begin());

    bool contiguous = true;
    T expected = *values.begin();
    for (const T& value : values)
    {
        if (value != expected)
        {
            contiguous = false;
            break;
        }
        ++expected;
    }

    if (contiguous)
        return std::to_string(*values.begin()) + ".." + std::to_string(*values.rbegin());

    std::ostringstream output;
    bool first = true;
    for (const T& value : values)
    {
        if (!first)
            output << ',';
        output << value;
        first = false;
    }
    return output.str();
}

sample_stats summarize(const std::vector<double>& values, double trim_fraction)
{
    sample_stats stats;
    if (values.empty())
        return stats;

    std::vector<double> sorted = values;
    std::sort(sorted.begin(), sorted.end());

    const std::size_t middle = sorted.size() / 2;
    if (sorted.size() % 2 != 0)
        stats.median = sorted[middle];
    else
        stats.median = (sorted[middle - 1] + sorted[middle]) / 2.0;

    std::size_t trim = static_cast<std::size_t>(static_cast<double>(sorted.size()) * trim_fraction);
    if (trim * 2 >= sorted.size())
        trim = 0;

    const std::size_t first = trim;
    const std::size_t last = sorted.size() - trim;
    const std::size_t count = last - first;

    stats.mean = std::accumulate(sorted.begin() + static_cast<std::ptrdiff_t>(first),
                                 sorted.begin() + static_cast<std::ptrdiff_t>(last),
                                 0.0) /
                 static_cast<double>(count);

    double variance = 0.0;
    for (std::size_t index = first; index < last; ++index)
        variance += (sorted[index] - stats.mean) * (sorted[index] - stats.mean);
    variance /= count > 1 ? static_cast<double>(count - 1) : 1.0;
    stats.standard_deviation = std::sqrt(variance);
    return stats;
}

class TinyUCBenchReporter final : public Catch::StreamingReporterBase
{
public:
    explicit TinyUCBenchReporter(Catch::ReporterConfig&& config)
        : Catch::StreamingReporterBase(std::move(config))
    {
        const auto trim_option = m_customOptions.find("Xtrim");
        if (trim_option != m_customOptions.end())
        {
            try
            {
                std::size_t consumed = 0;
                const double parsed = std::stod(trim_option->second, &consumed);
                if (consumed == trim_option->second.size() && std::isfinite(parsed) &&
                    parsed >= 0.0 && parsed < 50.0)
                    m_trim_percent = parsed;
            }
            catch (const std::exception&)
            {
            }
        }

        const auto markdown_option = m_customOptions.find("Xmarkdown");
        if (markdown_option != m_customOptions.end())
            m_markdown_path = markdown_option->second;
    }

    static std::string getDescription()
    {
        return "TinyUC benchmark tables";
    }

    void benchmarkEnded(Catch::BenchmarkStats<> const& stats) override
    {
        benchmark_row row;
        row.name = stats.info.name;
        row.sample_count = stats.samples.size();
        row.iterations = stats.info.iterations;
        row.samples.reserve(stats.samples.size());
        for (const Catch::Benchmark::FDuration& sample : stats.samples)
            row.samples.push_back(sample.count());

        const std::string suite_name =
            currentTestCaseInfo != nullptr ? currentTestCaseInfo->name : std::string();
        suite(suite_name).rows.push_back(std::move(row));
    }

    void benchmarkFailed(Catch::StringRef benchmarkName) override
    {
        const std::string suite_name =
            currentTestCaseInfo != nullptr ? currentTestCaseInfo->name : std::string();
        m_failures.push_back({suite_name, static_cast<std::string>(benchmarkName)});
    }

    void testRunEnded(Catch::TestRunStats const& stats) override
    {
        print_console();
        if (!m_markdown_path.empty())
            print_markdown();

        Catch::StreamingReporterBase::testRunEnded(stats);
    }

private:
    struct failure
    {
        std::string suite;
        std::string name;
    };

    benchmark_suite& suite(const std::string& name)
    {
        for (benchmark_suite& existing : m_suites)
        {
            if (existing.name == name)
                return existing;
        }

        m_suites.push_back({name, {}});
        return m_suites.back();
    }

    sample_stats stats_for(const benchmark_row& row) const
    {
        return summarize(row.samples, m_trim_percent / 100.0);
    }

    void print_banner()
    {
        std::size_t benchmark_count = 0;
        std::set<std::size_t> sample_counts;
        std::set<int> iteration_counts;
        for (const benchmark_suite& current : m_suites)
        {
            for (const benchmark_row& row : current.rows)
            {
                ++benchmark_count;
                sample_counts.insert(row.sample_count);
                iteration_counts.insert(row.iterations);
            }
        }

        if (benchmark_count == 0)
            return;

        if (!g_bench_info.empty())
            m_stream << g_bench_info << "\n\n";

        m_stream << "Running " << benchmark_count << " benchmarks in " << m_suites.size()
                 << " suites (samples=" << format_set(sample_counts)
                 << ", trim=" << format_percent(m_trim_percent)
                 << "%, iter=" << format_set(iteration_counts) << ")\n\n";
    }

    void print_console()
    {
        print_banner();

        for (std::size_t suite_index = 0; suite_index < m_suites.size(); ++suite_index)
        {
            const benchmark_suite& current = m_suites[suite_index];
            if (current.rows.empty())
                continue;

            std::vector<sample_stats> stats;
            stats.reserve(current.rows.size());
            for (const benchmark_row& row : current.rows)
                stats.push_back(stats_for(row));

            std::vector<std::string> names;
            std::vector<std::string> mean_values;
            std::vector<std::string> median_values;
            std::vector<std::string> deviation_values;
            std::vector<std::string> rates;
            names.reserve(current.rows.size());
            for (std::size_t index = 0; index < current.rows.size(); ++index)
            {
                const sample_stats& row_stats = stats[index];
                names.push_back(current.rows[index].name);
                mean_values.push_back(format_time(row_stats.mean));
                median_values.push_back(format_time(row_stats.median));
                deviation_values.push_back(format_time(row_stats.standard_deviation));
                rates.push_back(
                    format_rate(row_stats.mean > 0.0 ? 1000000000.0 / row_stats.mean : 0.0));
            }

            std::size_t name_width = std::string("name").size();
            std::size_t mean_width = std::string("mean").size();
            std::size_t median_width = std::string("median").size();
            std::size_t deviation_width = std::string("std dev").size();
            std::size_t rate_width = std::string("calls/s").size();
            for (std::size_t index = 0; index < names.size(); ++index)
            {
                name_width = std::max(name_width, names[index].size());
                mean_width = std::max(mean_width, mean_values[index].size());
                median_width = std::max(median_width, median_values[index].size());
                deviation_width = std::max(deviation_width, deviation_values[index].size());
                rate_width = std::max(rate_width, rates[index].size());
            }

            if (suite_index != 0)
                m_stream << '\n';

            const std::string title = "suite " + current.name;
            m_stream << std::string(title.size(), '-') << '\n'
                     << title << '\n'
                     << std::string(title.size(), '-') << "\n\n";

            m_stream << std::left << std::setw(static_cast<int>(name_width)) << "name" << "  "
                     << std::right << std::setw(static_cast<int>(mean_width)) << "mean" << "  "
                     << std::setw(static_cast<int>(median_width)) << "median" << "  "
                     << std::setw(static_cast<int>(deviation_width)) << "std dev" << "  "
                     << std::setw(static_cast<int>(rate_width)) << "calls/s" << '\n';

            const std::size_t rule_width =
                name_width + mean_width + median_width + deviation_width + rate_width + 8;
            m_stream << std::string(rule_width, '-') << '\n';

            for (std::size_t index = 0; index < names.size(); ++index)
            {
                m_stream << std::left << std::setw(static_cast<int>(name_width)) << names[index]
                         << "  " << std::right << std::setw(static_cast<int>(mean_width))
                         << mean_values[index] << "  " << std::setw(static_cast<int>(median_width))
                         << median_values[index] << "  "
                         << std::setw(static_cast<int>(deviation_width)) << deviation_values[index]
                         << "  " << std::setw(static_cast<int>(rate_width)) << rates[index] << '\n';
            }

            m_stream << std::string(rule_width, '-') << '\n';
        }

        for (const failure& failed : m_failures)
        {
            m_stream << "\nFAILED " << failed.suite << "::" << failed.name << '\n';
        }
    }

    void print_markdown()
    {
        std::ofstream output(m_markdown_path.c_str());
        if (!output)
        {
            m_stream << "\nwarning: could not write markdown report to " << m_markdown_path << '\n';
            return;
        }

        std::size_t benchmark_count = 0;
        std::set<std::size_t> sample_counts;
        std::set<int> iteration_counts;
        for (const benchmark_suite& current : m_suites)
        {
            for (const benchmark_row& row : current.rows)
            {
                ++benchmark_count;
                sample_counts.insert(row.sample_count);
                iteration_counts.insert(row.iterations);
            }
        }

#ifdef TINYUC_COMPARE
        output << "# TinyUC comparison benchmarks\n\n";
#else
        output << "# TinyUC benchmarks\n\n";
#endif
        if (!g_bench_info.empty())
            output << g_bench_info << "\n\n";

        output << "Running " << benchmark_count << " benchmarks in " << m_suites.size()
               << " suites (samples=" << format_set(sample_counts)
               << ", trim=" << format_percent(m_trim_percent)
               << "%, iter=" << format_set(iteration_counts) << ")\n\n";

        for (const benchmark_suite& current : m_suites)
        {
            if (current.rows.empty())
                continue;

            output << "## " << current.name << "\n\n"
                   << "| name | mean | median | std dev | calls/s |\n"
                   << "|---|---:|---:|---:|---:|\n";

            for (const benchmark_row& row : current.rows)
            {
                const sample_stats stats = stats_for(row);
                const double rate = stats.mean > 0.0 ? 1000000000.0 / stats.mean : 0.0;
                output << "| " << row.name << " | " << format_time(stats.mean) << " | "
                       << format_time(stats.median) << " | "
                       << format_time(stats.standard_deviation) << " | " << format_rate(rate)
                       << " |\n";
            }
            output << '\n';
        }
    }

    double m_trim_percent = 5.0;
    std::string m_markdown_path;
    std::vector<benchmark_suite> m_suites;
    std::vector<failure> m_failures;
};

} // namespace

void tinyuc_bench_set_info(std::string info)
{
    g_bench_info = std::move(info);
}

CATCH_REGISTER_REPORTER("tinyuc", TinyUCBenchReporter)
