#include <benchmark/benchmark.h>
#include "diff.h"

// Define another benchmark
static void DiffCpp_Benchmark(benchmark::State& state) {

  for (auto _ : state) {

    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase4/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase4/Input2.txt";

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                  linesFile2 = session.getLinesFromFile(argv[2]);

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);
  }
}
BENCHMARK(DiffCpp_Benchmark);


BENCHMARK_MAIN();
