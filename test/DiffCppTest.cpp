#include <gtest/gtest.h>
#include "../include/diff.h"

// Load Expected Results from the specified file
vector<string> loadExpectedResults(string path)
{

    vector<string> lines;
    fstream inputFile;
    string singleLine;

    inputFile.open(path);

    // Check that the specified file can open successfully
    if (inputFile.is_open())
    {

        while (getline(inputFile, singleLine))
        {
            lines.push_back(singleLine);
        }
        inputFile.close();
    }
    // Terminate the program
    else
    {
        cout << "Can not open the specified directory - No such file or folder" << endl;
        exit(EXIT_FAILURE);
    }

    return lines;
}

TEST(BlockTest1, CheckingSimpleDiff)
{
    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase1/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase1/Input2.txt";

    string lineToCheck;

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase1/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size())
    {
        cout << "Unequal size of commits list" << endl;
        EXPECT_TRUE(false);
    }

    else
    {
        for (int i = 0; i < diff.size(); i++)
        {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(BlockTest2, ComparePythonCode)
{
    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase2/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase2/Input2.txt";

    string lineToCheck;

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase2/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size())
    {
        cout << "Unequal size of commits list" << endl;
        EXPECT_TRUE(false);
    }

    else
    {
        for (int i = 0; i < diff.size(); i++)
        {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(BlockTest3, CompareCppCode)
{
    char *argvArray[4];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase3/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase3/Input2.txt";
    argvArray[3] = (char *)"/W";

    string lineToCheck;

    DiffSession session(4, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase3/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size())
    {
        cout << "Unequal size of commits list" << endl;
        EXPECT_TRUE(false);
    }

    else
    {
        for (int i = 0; i < diff.size(); i++)
        {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(BlockTest4, CheckingComplexDiff)
{
    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase4/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase4/Input2.txt";

    string lineToCheck;

    DiffSession session(3, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase4/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size())
    {
        cout << "Unequal size of commits list" << endl;
        EXPECT_TRUE(false);
    }

    else
    {
        for (int i = 0; i < diff.size(); i++)
        {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }
        EXPECT_TRUE(true);
    }
}

TEST(BlockTest5, CheckingJavaCode)
{
    char *argvArray[4];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase5/Input1.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase5/Input2.txt";
    argvArray[3] = (char *)"/W";

    string lineToCheck;

    DiffSession session(4, argv);

    vector<string> linesFile1 = session.getLinesFromFile(argv[1]),
                   linesFile2 = session.getLinesFromFile(argv[2]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/BlockTests/TestCase5/ExpectedResults.txt");

    vector<vector<string>> diff = session.getDiff(linesFile1, linesFile2);

    if (expectedOutput.size() != diff.size())
    {
        cout << "Unequal size of commits list" << endl;
        EXPECT_TRUE(false);
    }

    else
    {
        for (int i = 0; i < diff.size(); i++)
        {
            lineToCheck = "[" + diff[i][0] + "]" + diff[i][1];
            EXPECT_EQ(lineToCheck, expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(UnitTest1, CheckingLoadingLines)
{
    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/UnitTests/TestCase1/Input.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/UnitTests/TestCase1/Input.txt";

    DiffSession session(3, argv);

    vector<string> linesFile = session.getLinesFromFile(argv[1]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/UnitTests/TestCase1/ExpectedResults.txt");

    for (int i = 0; i < linesFile.size(); i++)
    {
        cout << linesFile[i] << endl;
    }

    if (expectedOutput.size() != linesFile.size())
    {
        cout << "Unequal size of commits list" << endl;
        EXPECT_TRUE(false);
    }

    else
    {
        for (int i = 0; i < linesFile.size(); i++)
        {
            EXPECT_EQ(linesFile[i], expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}

TEST(UnitTest2, CheckingLoadingLinesComplex)
{
    char *argvArray[3];
    char **argv = argvArray;
    argvArray[1] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/UnitTests/TestCase2/Input.txt";
    argvArray[2] = (char *)"/home/runner/work/DiffCpp/DiffCpp/test/UnitTests/TestCase2/Input.txt";

    DiffSession session(3, argv);

    vector<string> linesFile = session.getLinesFromFile(argv[1]);

    vector<string> expectedOutput =
        loadExpectedResults("/home/runner/work/DiffCpp/DiffCpp/test/UnitTests/TestCase2/ExpectedResults.txt");

    for (int i = 0; i < linesFile.size(); i++)
    {
        cout << linesFile[i] << endl;
    }

    if (expectedOutput.size() != linesFile.size())
    {
        cout << "Unequal size of commits list" << endl;
        EXPECT_TRUE(false);
    }

    else
    {
        for (int i = 0; i < linesFile.size(); i++)
        {
            EXPECT_EQ(linesFile[i], expectedOutput[i]);
        }

        EXPECT_TRUE(true);
    }
}