# Benchmarks

## Unicode Normalization

The normalization suite uses the [Unicode Normalization Test Suite 17.0.0](https://www.unicode.org/Public/17.0.0/ucd/NormalizationTest.txt) from UCD.
Differences between Unicode versions have not been considered but should be negligible.

We iterate the 20,034 cases for each of the source columns (source, NFC, NFD, NFKC, NFKD) and apply each normalization form.
In total 400,680 conversions per benchmark call.

Versions tested:
* TinyUC 0.4.0 (Unicode 17.0.0)
* utf8proc 2.12.0 (Unicode 18.0.0)
* ICU 
  * Windows: 72.1 (Windows Built-in, Unicode 15.1.0)
  * Fedora 42: 76.1 (Unicode 16.0.0)

All libraries are dynamically linked and tested against C-APIs.

Implementations compared:
- normalization — tinyuc_normalize (quick-check fast path).
- normalization-without-quickpath — tinyuc_normalize_full (control, always full algorithm, internal only).
- normalization-utf8proc — utf8proc_map with STABLE + COMPOSE/DECOMPOSE/COMPAT.
- normalization-icu — ICU C API unorm2_normalize with NFD/NFC/NFKD/NFKC instances; ICU is UTF-16, so this row includes the UTF-8→UTF-16→normalize→UTF-16→UTF-8 round trip. Not that fair, but since our philosophy is UTF-8 everywhere, this is what matters.

### Windows

```
Running 4 tests in 1 suites (samples=500, trim=5%)
name                                      mean    median   std dev   calls/s
-----------------------------------------------------------------------
normalization                         23.91 ms  23.84 ms  280.7 us  41.82 /s
normalization-without-quickpath       35.51 ms  35.47 ms  273.4 us  28.16 /s
normalization-ssse3                   23.33 ms  23.34 ms  134.3 us  42.86 /s
normalization-without-quickpath       35.01 ms  34.91 ms  337.9 us  28.57 /s
normalization-avx2                    23.29 ms  23.32 ms  122.5 us  42.94 /s
normalization-avx2-without-quickpath  34.39 ms  34.44 ms  146.5 us  29.08 /s
normalization-utf8proc                34.29 ms  34.11 ms  453.2 us  29.16 /s
normalization-icu                     48.36 ms  48.40 ms  263.3 us  20.68 /s
```

## Linux

```
Running 4 tests in 1 suites (samples=500, trim=5%)
name                                 mean    median   std dev   calls/s
-----------------------------------------------------------------------
normalization                    17.20 ms  17.15 ms  338.6 us  58.14 /s
normalization-without-quickpath  25.54 ms  25.51 ms  407.7 us  39.15 /s
normalization-utf8proc           17.94 ms  17.91 ms  287.6 us  55.73 /s
normalization-icu                42.01 ms  41.95 ms  504.3 us  23.80 /s
```

## Verdict

- TinyUC is faster than ICU on both Windows and Linux on this specific suite. The suite was not specifically chosen to beat anything.
- utf8proc seems penalized in lack of a quick normalization check. The core algorithm is fast (compare against normalization-without-quickpath).
- ICU is penalized since it expects UTF-16.
- This is before any targeted optimizations in the TinyUC library.

## UTF-8 decoder and counter

The library uses a single scalar decoder (`tinyuc_utf8_decode`): a branch chain
on the lead byte, then a few shifts to assemble the codepoint. It was the
fastest of the scalar decoders measured (see "Alternative algorithms explored").

The `utf8-decoder` suite decodes an ASCII-heavy ~1 MiB buffer plus the five
source forms of the UCD corpus concatenated (non-ASCII heavy). `decode` sums
every codepoint; `count` only counts them. Run it with
`tinyuc_benchmarks -s utf8-decoder -v`.

Windows (samples=500, trim=10%):

```
name    mean     median   calls/s
-----------------------------------
decode  788.2 us 775.8 us 1.269 k/s
count   648.5 us 644.8 us 1.542 k/s
```

### Verdict

- The branch-chain decoder is the winner; the alternatives documented below
  were slower.
- `tinyuc_num_cp()` uses the SIMD counter when available and this scalar counter
  otherwise. The scalar counter is a flat loop rather than the generic
  `FOR_EACH_CODEPOINT` helper; going through the helper is about 2x slower for a
  pure count because the iterator pointer is address-taken.

## SIMD validation and counting

An optional SIMD path accelerates UTF-8 validation and codepoint counting. It is
a 32-byte adaptation of the SIMD "lookup" algorithm by Keiser and Lemire (as
used by simdjson); the counter uses the fact that a codepoint has exactly one
non-continuation byte. The 16-byte variant is the same algorithm on narrower
vectors.

Tiers, selected with `-DTINYUC_SIMD=<value>`:

| value | kernels | requirement |
| --- | --- | --- |
| `AUTO` | all tiers the architecture supports | picked at runtime (default) |
| `AVX2` | 32-byte | x86-64 with AVX2 |
| `SSSE3` | 16-byte | x86-64 with SSSE3 |
| `OFF` | none | portable C only |

`AUTO` compiles the 16- and 32-byte kernels on x86 and dispatches at runtime. The
tier is chosen once by `tinyuc_simd_detect()` (CPUID, plus OSXSAVE/XCR0 for AVX2)
and then read from a cached integer, so the per-call check is a load and a
branch. Every kernel call is guarded, so a binary built with a higher tier still
loads and runs on a CPU without those instructions and falls back to the next
compiled tier, then to the portable code.

The `utf8-simd` suite validates and counts the same ASCII-heavy ~1 MiB buffer and
concatenated corpus used by `utf8-decoder`. The `-lib` rows go through the public
API; the `-scalar` rows are an independent portable reference.

Windows, samples=1000, trim=10%:

```
tier    test             mean     median   vs scalar
----------------------------------------------------------
scalar  validate-lib     1.098 ms 826.5 us 1.0x
AVX2    validate-lib     43.6 us  42.1 us  ~20x
SSSE3   validate-lib     101 us   91.3 us  ~10x
scalar  count-lib        986.7 us 792.5 us 1.0x
AVX2    count-lib        30.1 us  29.9 us  ~30x
SSSE3   count-lib        87.1 us  83.4 us  ~11x
```

### Verdict

- AVX2 validation is roughly 20x and counting roughly 30x faster than the scalar
  loop on this mixed workload. The 16-byte SSSE3 tier still gives about 10x with
  a far wider hardware base. Both scale further with the ASCII share of the
  input.
- SIMD is enabled by default (`AUTO`). `AUTO` decides *at configure time* only
  which tiers to compile for the target architecture (x86: SSSE3/AVX2; other
  architectures: none); which tier to actually use is decided *at runtime* by
  CPUID. Every kernel call is guarded, so an `AUTO` build is portable across x86
  CPUs of any age, and on non-x86 targets it compiles no SIMD at all. `OFF`
  removes the ISA-specific objects entirely (smaller plain-C binary), which is
  useful for size or auditing but is not required for portability.
- These tiers accelerate `tinyuc_validate()` and `tinyuc_num_cp()` only. They do
  not touch the per-codepoint iterator, so normalization throughput is
  unchanged (measured within noise: scalar 23.9 ms vs AVX2 23.5 ms, same
  session). See "UTF-8 decoder and counter" above.

### Lowest bar

For 64-bit targets SIMD is effectively always available in some form, so a
baseline tier can be compiled unconditionally:

| architecture | guaranteed baseline | enables |
| --- | --- | --- |
| x86-64 | SSE2 (ABI) | counting / ASCII fast path |
| x86-64 (practically) | SSSE3 | the lookup validator (needs `pshufb`) |
| AArch64 | NEON (ABI) | counting and the lookup validator |

- On x86-64, SSE2 is guaranteed by the ABI but lacks `PSHUFB`, so the lookup
  validator needs **SSSE3**, which every x86-64 part since ~2006 provides. That
  is the practical lowest bar for validation; a pure-SSE2 validator would need a
  different (non-shuffle) classification scheme, which is not worth the
  complexity while SSSE3-only CPUs are effectively extinct in 64-bit.
- On AArch64, NEON is mandatory and has a byte shuffle (`vqtbl1q_u8`), so the
  same lookup algorithm maps directly onto it. Implementing that backend is
  still pending (it cannot be built or benchmarked on the current x86 dev
  machine).

## Alternative algorithms explored

Non-SIMD alternatives were prototyped and rejected: a branchless decoder, a wide
ASCII counter, bulk materialization, and a portable DFA. See
[Alternatives.md](Alternatives.md) for each algorithm, the part of the library it
was meant to replace, and the measurements.

## Test system

| - | Windows | Linux |
| --- | --- | --- |
| OS | Windows 11 26H1 (26300.9711) | Fedora 42 (WSL) |
| Compiler | MSVC 19.44.35217 | GCC 15.2.1 |
| Release flags | /O2 | -O3 |

Machine specs:

```
AMD Ryzen 7 7700X 8-Core Processor
Kingston 32 GB DDR5 at 6000 MHz
```

## Note on sizes

Size comparison may be interesting in embedding.

The TinyUC library includes case mapping, case folding and grapheme segmentation in addition to normalization.
ICU includes a lot more functionality than just normalization. The sizes here are only an indication and not investigated in full.

Windows:

| Binary | Size |
| --- | --- |
| tinyuc.dll | 353 KB |
| utf8proc.dll | 354 KB |
| icu.dll (System32) | 2.67 MB |
| icuuc.dll (System32) | 36 KB |

Note: icuuc.dll only forwards to icu.dll.

Linux:

| Binary | Size | Stripped |
| --- | --- | --- |
| libtinyuc.so | 422K KB | 379 KB |
| libutf8proc.so | 361 KB | - |
| libicuuc.so.76 | 2.03 MB | - |
| libicudata.so.76 | 30.4 MB | - |
