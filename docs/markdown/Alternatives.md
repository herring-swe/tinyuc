# Alternative algorithms explored

This document records implementations that were prototyped, benchmarked and
rejected. They are grouped by the part of the library each was intended to
replace. None of them remain in the code; the descriptions and numbers are kept
so they do not have to be re-explored.

The test machine was an AMD Ryzen 7 7700X, Windows 11, MSVC 19.44 Release
(`/O2 /Ob2`); the Linux rows in [Benchmarks.md](Benchmarks.md) use GCC 15.2.1.
Unless stated otherwise, buffers are an ASCII-heavy ~1 MiB buffer plus the five
source forms of the UCD Normalization Test corpus concatenated.

---

## Codepoint decoding

Intended replacement: the per-codepoint decoder `tinyuc_utf8_decode`, i.e. the
decode step of the `FOR_EACH_CODEPOINT` iterator used by normalization, case
mapping and grapheme segmentation.

The selected implementation is a branch chain on the lead byte, then a few shifts
to assemble the codepoint. Both alternatives below lost to it.

### Branchless arithmetic decoder

- **What it replaced:** `tinyuc_utf8_decode` (one codepoint per call).
- **Algorithm:** derive the sequence length from the lead byte with two
  comparisons (`2 + (b0 >= 0xE0) + (b0 >= 0xF0)`), select a masks from a small
  table, then fold the continuation bytes in without a branch chain.
- **Result:** ~1.7x slower than the branch chain (`decode-alt` 946.8 us vs
  `decode` 560.6 us on the same buffers). The arithmetic and index lookups add
  work, while the branch chain's lead-byte branches are already well predicted.
- **Status:** removed.

### Portable DFA decoder

- **What it replaced:** the codepoint iterator loop as a whole (a stream state
  machine over the bytes, rather than a decode call per codepoint).
- **Algorithm:** [Björn Höhrmann's table-driven
  DFA](http://bjoern.hoehrmann.de/utf-8/decoder/dfa/). The first 256 table bytes
  map a byte to a character class; 108 transition bytes advance the state. A
  codepoint is emitted when the automaton returns to the accept state. It was
  integrated as one **flat loop over bytes**: `FOR_EACH_CODEPOINT` carried the
  state and applied a loop-free `step(state, byte, &cp)` to each byte, running
  the caller's block only on accept. (Restarting the automaton per codepoint, or
  hiding the byte loop inside a per-codepoint call, defeats the design and was
  not the version measured.)

- **Pure decode** (sum of codepoints, samples=1000, trim=10%):

  ```
  name          mean      median    vs branch chain
  ---------------------------------------------------
  decode        559.9 us  559.2 us  1.0x
  decode-dfa    1.837 ms  1.839 ms  ~3.3x slower
  ```

- **Normalization** (library built with the DFA loop vs the branch-chain loop,
  SIMD off, samples=300, trim=10%, two runs each):

  ```
  path                          branch chain        DFA
  ---------------------------------------------------------------
  normalization (quick)         24.08 / 23.83 ms    24.68 / 24.85 ms
  normalization-without-quick   35.99 / 35.69 ms    35.91 / 36.17 ms
  ```

- **Optimization level does not change the outcome** (direct kernel benchmark,
  16 MiB buffers, QPC, best of 40):

  ```
  build                       ASCII ref   ASCII DFA   mixed ref   mixed DFA
  ---------------------------------------------------------------------------
  MSVC /O2                    6.11 ms     18.4 ms     5.18 ms     18.7 ms
  clang -O2                   4.70 ms     18.8 ms     4.88 ms     18.7 ms
  clang -O3                   6.11 ms     18.8 ms     4.87 ms     18.6 ms
  clang -O3 -march=native     6.12 ms     19.0 ms     4.74 ms     18.6 ms
  ```

  The DFA sits at a ~0.9 GB/s wall on every compiler and flag; the branch chain
  moves between ~2.7 and ~3.6 GB/s and still wins by 3-4x.

- **Why it loses:**
  1. *Per byte vs per codepoint.* The branch chain does one small decision tree
     per codepoint (2-4 bytes). The DFA does two table lookups plus arithmetic
     per byte, i.e. 2-4x the iterations on non-ASCII text.
  2. *Latency-bound.* The state is a serial `state -> index -> load -> state`
     dependency, so L1 load latency cannot be hidden. That is the ~4 cycles per
     byte behind the 0.9 GB/s wall, and why the number is identical across
     compilers.
  3. *Branches are cheap here.* UTF-8 is structured, so the branch chain's
     branches predict almost perfectly. Branchless designs win on unpredictable
     input or in-order CPUs.
  4. *The DFA's fix cannot decode.* Interleaving two DFAs (Höffken's
     double/interleaved variant) hides the load latency by running two streams,
     but interleaving even/odd bytes cannot assemble codepoints, so it is
     validation-only.

- **Status:** removed.

---

## Codepoint counting

Intended replacement: the scalar count used by `tinyuc_num_cp` when no SIMD
counter is available.

### Wide ASCII counting iterator

- **What it replaced:** the scalar `tinyuc_num_cp` path.
- **Algorithm:** consume runs of eight ASCII bytes per 64-bit mask test, count
  non-continuation bytes (one per codepoint), and fall back to a byte loop for
  non-ASCII and the tail.
- **Result:** ~1.9x faster than the decode-based scalar count (`count-alt`
  349.2 us vs `count` 658.8 us). However, the SIMD counter is ~10-30x faster than
  the scalar count and is the actual default when available, so this middle tier
  adds code for a gap nobody observes. The straightforward scalar fallback is
  enough.
- **Status:** removed.

---

## Iteration strategy

Intended replacement: the streaming codepoint iteration used by single-pass
algorithms (normalization, case mapping, grapheme segmentation).

### Bulk materialization

- **What it replaced:** streaming iteration; the idea was to decode the entire
  buffer to a `uint32_t` array once and then work on codepoints.
- **Algorithm:** one decode pass into a reused, preallocated `uint32_t` array,
  then process the array.
- **Result:** ~1.3x slower for single-pass work even with the allocation removed
  from the measurement:

  ```
  name          mean     median   vs streaming
  ----------------------------------------------
  decode        560.6 us 560.9 us 1.0x
  decode-bulk   707.6 us 704.0 us ~1.3x slower
  ```

  It adds a write pass and 4x memory traffic (4 bytes per codepoint, worst case
  4x the input), and a whole-string UTF-32 copy evicts cache on large inputs. It
  only pays off when the codepoints are consumed more than once or accessed out
  of order (e.g. collation).
- **If more speed is needed:** the productive structure is a *chunked* iterator —
  decode a few thousand codepoints into a cache-resident buffer, process them,
  repeat. That keeps the streaming memory profile, avoids per-string allocation,
  removes per-call overhead, and leaves room for a SIMD transcode per chunk.
- **Status:** removed.
