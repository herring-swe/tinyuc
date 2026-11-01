# Unicode implementation

The unicode module operates on UTF-8 encoded strings. It is built on
compile-time generated Unicode Character Database (UCD) tables kept in
`src/private/unicode/` as internal headers. The tables are generated from the
official UCD files by `tools/ucparser.py` and checked in, so a normal build
needs no Unicode data, Python or network access. No runtime data files or
external dependencies are needed.

The official UCD files are shipped compressed in `data/ucd/` and extracted on
demand. A local file that does not match its expected hash is downloaded
again, which keeps version updates manageable.

Regenerate the headers after a UCD or parser change with
`-DTINYUC_GENERATE_UNICODE_DATA=ON`. To check that the checked-in headers match
the generator output without modifying the source tree, configure with
`-DTINYUC_VERIFY_UNICODE_DATA=ON` and build the `verify_unicode_data` target.

## Supported features

- UTF-8 validation, decoding (`tinyuc_iter_utf8`) and encoding
  (`tinyuc_encode_codepoint`, `tinyuc_encode_codepoints_buf`).
- Codepoint counting (`tinyuc_num_cp`).
- Extended grapheme cluster support per UAX #29 (`tinyuc_num_char`,
  `tinyuc_char_index`, `tinyuc_next_char`), including Hangul, regional
  indicators, emoji ZWJ sequences, emoji modifiers and Indic conjuncts.
- Normalization: NFC, NFD, NFKC and NFKD, with a quick-check fast path and a
  full fallback.
- Full case folding and case mapping (`tinyuc_to_upper`, `tinyuc_to_lower`,
  `tinyuc_to_title`, `tinyuc_casefold`).
- Case-insensitive comparison (`tinyuc_icomp`).

## Design notes

- UTF-8 uses the same byte count as code units, so byte offsets are code unit
  offsets. All `_byte` parameters refer to validated boundaries.
- Property lookups use a two-stage table plus a compact property record. Only
  codepoints that carry a decomposition, mapping, combiner or grapheme/Indic
  property have extra data.
- The normalization quick check is conservative: it only reports "already
  normalized" when that is guaranteed, otherwise the full algorithm runs.
- Canonical reordering uses a stack window that grows to the heap for long
  segments; canonical segments have no upper bound and are not truncated.

## Conformance testing

The test suite validates against the official Unicode data files:

- `NormalizationTest.txt`: 20,034 test definitions, each exercised through 20
  normalization relationships (input, NFC, NFD, NFKC, NFKD in all four target
  forms).
- `GraphemeBreakTest.txt`: 766 grapheme break tests, also checking
  `tinyuc_num_char()` and `tinyuc_char_index()` against the expected boundaries.

Additional unit tests cover UTF-8 validation, encoding/decoding boundaries,
case mapping, normalization forms and the codepoint/grapheme counting helpers.

## Remaining limitations and proposals

- **`tinyuc_char_index(str, len, 0)` returns `len`.** Index 0 is not a valid
  1-based index; this is documented, but a distinct sentinel or an error
  would be clearer.
- **`tinyuc_iter_utf8()` has no end check.** It decodes a null byte as U+0000,
  which is indistinguishable from the terminator of a null-terminated string.
  Iterating strings with embedded nulls requires an explicit length. *Proposed
  addition:* a length-aware iterator or one returning a status.

## Possible additions

- Context-sensitive (for example Final_Sigma) and locale-aware case mappings.
- UTF-16 and UTF-32 conversion to/from UTF-8.
- Case-insensitive collation and, when available, system collation.
- A streaming, allocation-free case-insensitive comparison built on
  `tinyuc_icomp()`.
- Optional backend selection for collation and segmentation.
