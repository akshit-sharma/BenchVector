# BenchVector ![C/C++ CI](https://github.com/akshit-sharma/BenchVector/workflows/C/C++%20CI/badge.svg)
A repository for bench marking at and [] on vector.

## Prerequisites
[conan](https://docs.conan.io/en/1.7/installation.html) `pip install conan`

## To build
1. clone the repository and `cd` into root of repo.
2. `mkdir build && cd build`
3. `cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..`
4. `make`
5. `./bin/bench`

Run on (12 X 4100 MHz CPU s)
CPU Caches:
  L1 Data 32K (x6)
  L1 Instruction 32K (x6)
  L2 Unified 256K (x6)
  L3 Unified 9216K (x1)
Load Average: 0.37, 0.59, 0.55
|-------------------------------------------------------------------|
|Benchmark            |        Time   |          CPU  | Iterations  |
|-------------------------------------------------------------------|
|BM\_CREATION/10      |      18.5 ns  |       18.5 ns |    38523819 |
|BM\_CREATION/1000    |      1391 ns  |       1391 ns |      502031 |
|BM\_CREATION/100000  |    136898 ns  |     136899 ns |        5137 |
|BM\_CREATION/1000000 |   1370794 ns  |    1370821 ns |         504 |
|BM\_AT/10            |      1.14 ns  |       1.14 ns |   653686519 |
|BM\_AT/1000          |      1.04 ns  |       1.04 ns |   684879471 |
|BM\_AT/100000        |      1.04 ns  |       1.04 ns |   657157337 |
|BM\_AT/1000000       |      1.05 ns  |       1.05 ns |   672855023 |
|BM\_SQ/10            |      1.11 ns  |       1.11 ns |   631626603 |
|BM\_SQ/1000          |      1.11 ns  |       1.11 ns |   626209031 |
|BM\_SQ/100000        |      1.11 ns  |       1.11 ns |   629807535 |
|BM\_SQ/1000000       |      1.13 ns  |       1.13 ns |   618735409 |
|-------------------------------------------------------------------|

