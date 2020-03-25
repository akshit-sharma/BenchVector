# BenchVector ![C/C++ CI](https://github.com/akshit-sharma/BenchVector/workflows/C/C++%20CI/badge.svg)
A repository for bench marking at and [] on vector.

## Prerequisites
[conan](https://docs.conan.io/en/1.7/installation.html) [`pip install conan`]

## To build
1. clone the repository and `cd` into root of repo.
2. `mkdir build && cd build`
3. `cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..`
4. `make`
5. `./bin/bench`

# Output

```
Running ./Build/bin/bench
Run on (12 X 4100 MHz CPU s)
CPU Caches:
  L1 Data 32K (x6)
  L1 Instruction 32K (x6)
  L2 Unified 256K (x6)
  L3 Unified 9216K (x1)
Load Average: 0.16, 0.35, 0.46
--------------------------------------------------------------
Benchmark                    Time             CPU   Iterations
--------------------------------------------------------------
BM_CREATION/10            18.5 ns         18.5 ns     38587124
BM_CREATION/1000          1422 ns         1417 ns       490640
BM_CREATION/100000      139357 ns       139005 ns         5048
BM_CREATION/1000000    1390552 ns      1390067 ns          457
BM_AT/10                  1.11 ns         1.11 ns    632870227
BM_AT/1000                1.04 ns         1.04 ns    665083552
BM_AT/100000              1.05 ns         1.05 ns    668588598
BM_AT/1000000             1.06 ns         1.06 ns    655269091
BM_SQ/10                  1.12 ns         1.12 ns    624857672
BM_SQ/1000                1.14 ns         1.14 ns    626311328
BM_SQ/100000              1.13 ns         1.13 ns    623488558
BM_SQ/1000000             1.16 ns         1.15 ns    607213755

```
