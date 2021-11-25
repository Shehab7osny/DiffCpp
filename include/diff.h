#ifndef DIFF_H
#define DIFF_H

/****************************************************************************
 *Filename:          diff.h
 *Author:            Shehab Hosny
 *Date:	            1/11/2021
 *Version:           1.0
 *Description:       MED Qualification Task
 *Myers Algorithm    http://www.xmailserver.org/diff2.pdf
 ****************************************************************************/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

static const char *Starting_MSG =
    "+-------------------------------------------------+\n"
    "|        ____  _  __  __  ____                    |\n"
    "|       |  _ \\(_)/ _|/ _|/ ___|_ __  _ __         |\n"
    "|       | | | | | |_| |_| |   | '_ \\| '_ \\        |\n"
    "|       | |_| | |  _|  _| |___| |_) | |_) |       |\n"
    "|       |____/|_|_| |_|  \\____| .__/| .__/        |\n"
    "|                             |_|   |_|           |\n"
    "|                                                 |\n"
    "|       Version 1.0                               |\n"
    "+-------------------------------------------------+\n"
    "| DiffCpp  File1_Path  File2_Path  [/N] [/W] [/A] |\n"
    "|                                                 |\n"
    "| /N -> Display the line numbers                  |\n"
    "| /W -> Ignore Whitespaces                        |\n"
    "| /A -> Display the changes only                  |\n"
    "+-------------------------------------------------+\n";

/**
 * DiffSession
 *
 * This class provides the user a single session  (as in Windows FC diff tool)
 * to get the updates in two file versions. The user must pass atleast two
 * arguments in addition to the exe call. If any of these arguments are missing
 * the program will terminate. However, the user may add up to three additional
 * arguments for additional diff options indicated in the class constructor.
 * This class compares the two text files based on Myers' Algorithm of diff.
 */
class DiffSession {
public:
  /**
   * Construtor that starts a single session for files comparison
   *
   * @param noOfArgs Total number of arguments passed
   * @param argsList List of actual arguments passed
   */
  DiffSession(int noOfArgs, char **argsList);

  // Get the diff and Display it for the running session
  void showDiff();

  // Load the input file into a vector of separate lines
  vector<string> getLinesFromFile(string path);

  // An implementation of Myers Diff algorithm
  vector<vector<string>> getDiff(vector<string> linesFile1,
                                 vector<string> linesFile2);

  // Display the diff table including all commits
  void printTable(vector<vector<string>> result);

private:
  string filePath1, filePath2, fileName1, fileName2;
  bool printLineNumber = false, ignoreWhiteSpaces = false,
       displayUpdateOnly = false, isSameFile = true;

  // Extract file name from file path
  string getFileName(string path);

  // Check if two strings are the same whether whitespaces are included or not
  bool strCompare(string line1, string line2, bool ignoreSpace);
};

#endif
