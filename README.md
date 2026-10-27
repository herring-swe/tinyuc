# TinyUC

TinyUC - Tiny Unicode

A small C library for unicode handling with focus on UTF-8.

## Features

- Full Normalization (NFC, NFD, NFKC, NFKD)
- Case Folding
- Case Mapping
- Grapheme Cluster Boundaries

It aims to be small, portable and fast.

## Limitations

- No convertion from/to UTF-16 or UTF-32
- No plans for collation other than probably DUCET.
- No plans for regular expression support.

## Target

- C11 for the core library
  - Headers declare `extern "C"` for import into C++
  - Testing [doctest](https://github.com/doctest/doctest)] use C++
- OS:
  - Windows
  - Linux
- Compilers:
  - MSVC
  - GCC
  - Clang
- Build systems:
  - CMake
  
See [dependencies](#dependencies) for exact versions.

Anything not listed above is not tested and is not a priority. Please help out if you want additional support and are able to maintain it.

## Dependencies

This section needs verification.

- CMake 3.28 or later
- Python 3.6 or later (only for Unicode data generation scripts)

- MSVC:
  - The following are required for C11 support:
    - At least Visual Studio 2019 (v16.8)
  - At least Windows 10 SDK 10.0.20348.0
- Install python requirements:
  - python -m pip install -r tools/pyreq.txt

Development requirements (additional from above):

- Python 3.10 or later
- Install python requirements:
  - python -m pip install -r tools/pyreq-dev.txt
  
## Building

Simply use cmake.

Linux with GNU Make:

```bash
git clone git@github.com:herring-swe/tinyuc.git
mkdir tinyuc-build
cd tinyuc-build
cmake ../tinyuc -G "Unix Makefiles"
cmake --build .
```

For instance on Windows with Visual Studio 2022:

```bash
git clone git@github.com:herring-swe/tinyuc.git
mkdir tinyuc-build
cd tinyuc-build
cmake ../tinyuc -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

It is recommended to use Ninja.

## Contributing

Please report bugs or request features by creating an issue.
Any help are welcome. Especially MacOS support.
