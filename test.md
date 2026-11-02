# TinyUC benchmarks

Samples: trimmed 5% from each tail.

## normalization

| name | mean | median | std dev | calls/s |
|---|---:|---:|---:|---:|
| normalization | 23.68 ms | 23.70 ms | 124.9 us | 42.23 /s |
| normalization-without-quickpath | 39.47 ms | 39.43 ms | 432.6 us | 25.33 /s |
| normalization-icu | 48.14 ms | 48.04 ms | 546.9 us | 20.77 /s |

## utf8-simd

| name | mean | median | std dev | calls/s |
|---|---:|---:|---:|---:|
| validate-lib | 39.03 us | 38.79 us | 694.1 ns | 25.62 k/s |
| validate-scalar | 658.1 us | 660.3 us | 62.83 us | 1.519 k/s |
| count-lib | 30.85 us | 27.99 us | 3.377 us | 32.42 k/s |
| count-scalar | 849.0 us | 847.9 us | 4.305 us | 1.178 k/s |

