#include <benchmark/benchmark.h>

#include <limits>

static void BM_CREATION(benchmark::State &state) {
  size_t size = state.range(0);
  for (auto _ : state) {
    std::vector<int> vec;
    vec.reserve(size);
    for (size_t i = 0; i < size; ++i)
      vec.push_back(static_cast<int>(i));
  }
}
BENCHMARK(BM_CREATION)->Arg(10)->Arg(1000)->Arg(100000)->Arg(1000000);

static void BM_AT(benchmark::State &state) {
  size_t size = state.range(0);
  std::vector<int> vec;
  vec.reserve(size);
  for (size_t i = 0; i < size; ++i)
    vec.push_back(static_cast<int>(i));
  int index = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(vec.at(index));
    index = (index + 1 >= size) ? 0 : index + 1;
  }
}
BENCHMARK(BM_AT)->Arg(10)->Arg(1000)->Arg(100000)->Arg(1000000);

static void BM_SQ(benchmark::State &state) {
  size_t size = state.range(0);
  std::vector<int> vec;
  vec.reserve(size);
  for (size_t i = 0; i < size; ++i)
    vec.push_back(static_cast<int>(i));
  size_t acc = 0;
  int index = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(vec[index]);
    index = (index + 1 >= size) ? 0 : index + 1;
  }
}
BENCHMARK(BM_SQ)->Arg(10)->Arg(1000)->Arg(100000)->Arg(1000000);

BENCHMARK_MAIN();
