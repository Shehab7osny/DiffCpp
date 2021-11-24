#include <benchmark/benchmark.h>
#include "diff.h"

// Define another benchmark
static void BM_Diff_1(benchmark::State& state) {

  for (auto _ : state) {

    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase1/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase1/Input2.txt";

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                  linesFile2 = session.getLinesFromFile(argv[2]);

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);
  }
}
BENCHMARK(BM_Diff_1);

static void BM_Diff_2(benchmark::State& state) {

  for (auto _ : state) {

    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase2/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase2/Input2.txt";

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                  linesFile2 = session.getLinesFromFile(argv[2]);

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);
  }
}
BENCHMARK(BM_Diff_2);

static void BM_Diff_3(benchmark::State& state) {

  for (auto _ : state) {

    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase3/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase3/Input2.txt";

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                  linesFile2 = session.getLinesFromFile(argv[2]);

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);
  }
}
BENCHMARK(BM_Diff_3);

static void BM_Diff_4(benchmark::State& state) {

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
BENCHMARK(BM_Diff_4);

static void BM_Diff_5(benchmark::State& state) {

  for (auto _ : state) {

    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase5/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/"
                          "TestCase5/Input2.txt";

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                  linesFile2 = session.getLinesFromFile(argv[2]);

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);
  }
}
BENCHMARK(BM_Diff_5);

BENCHMARK_MAIN();
