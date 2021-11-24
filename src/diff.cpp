#include "diff.h"

DiffSession::DiffSession(int noOfArgs, char **argsList) {
  this->filePath1 = argsList[1]; // Old version file
  this->filePath2 = argsList[2]; // New version file
  this->fileName1 = getFileName(this->filePath1);
  this->fileName2 = getFileName(this->filePath2);

  // Assign additional options for the current session
  for (int i = 3; i < noOfArgs; i++) {
    if ((string)argsList[i] == "/N") {
      this->printLineNumber = true;
    } else if ((string)argsList[i] == "/W") {
      this->ignoreWhiteSpaces = true;
    } else if ((string)argsList[i] == "/A") {
      this->displayUpdateOnly = true;
    }
  }
}

void DiffSession::showDiff() {
  vector<string> linesFile1 = getLinesFromFile(this->filePath1),
                 linesFile2 = getLinesFromFile(this->filePath2);

  vector<vector<string>> diff = getDiff(linesFile1, linesFile2);

  printTable(diff);
}

vector<string> DiffSession::getLinesFromFile(string path) {
  vector<string> lines;
  fstream inputFile;
  string singleLine;

  inputFile.open(path);

  // Check that the specified file can open successfully
  if (inputFile.is_open()) {
    while (getline(inputFile, singleLine)) {
      lines.push_back(singleLine);
    }

    inputFile.close();
  }

  // Terminate the program
  else {
    cout << "Can not open the specified directory - No such file or folder"
         << endl;
    exit(EXIT_FAILURE);
  }

  return lines;
}

vector<vector<string>> DiffSession::getDiff(vector<string> linesFile1,
                                            vector<string> linesFile2) {
  // Myers' graph coordinates
  int x, y, xPrevious;

  int linesCount1 = linesFile1.size(), linesCount2 = linesFile2.size(),
      totalLinesCount = linesCount1 + linesCount2;

  // Hashmap to backtrack Myers' graph and get the best path of commits
  unordered_map<int, tuple<int, vector<vector<string>>>> mapGrid;

  // Commit history list with all Keeps, Insertions and Deletions
  vector<vector<string>> updateList;

  // Used to access the tuple elements
  const int xCoordinate = 0, lastUpdate = 1;

  for (int d = 0; d <= totalLinesCount; d++) {
    for (int k = -d; k <= d; k += 2) {
      // checkPath checks which of the 2 previous k values has the largest value
      // of x
      bool checkPath = get<xCoordinate>(mapGrid[k - 1]) <
                       get<xCoordinate>(mapGrid[k + 1]),
           moveDown = (k == -d) || (k != d && checkPath);

      // This is to add a line from the updated file
      if (moveDown) {
        updateList = get<lastUpdate>(mapGrid[k + 1]);
        xPrevious = get<xCoordinate>(mapGrid[k + 1]);
        x = xPrevious;
      }
      // moveRight - This is to delete a line from the old file
      else {
        updateList = get<lastUpdate>(mapGrid[k - 1]);
        xPrevious = get<xCoordinate>(mapGrid[k - 1]);
        x = xPrevious + 1;
      }

      y = x - k;

      // Update the history list with an Insertion
      if ((1 <= y && y <= linesCount2) && (moveDown)) {
        updateList.push_back({"Insert", linesFile2[y - 1]});
        if (this->isSameFile)
          this->isSameFile = false;
      }
      // Update the history list with a Deletion
      else if (1 <= x && x <= linesCount1) {
        updateList.push_back({"Delete", linesFile1[x - 1]});
        if (this->isSameFile)
          this->isSameFile = false;
      }

      // Handle similar lines in both files
      while (
          (x < linesCount1) && (y < linesCount2) &&
          (strCompare(linesFile1[x], linesFile2[y], this->ignoreWhiteSpaces))) {
        x++;
        y++;
        updateList.push_back({"Keep", linesFile1[x - 1]});
      }

      mapGrid[k] = make_tuple(x, updateList);

      // Check if File1 is completely converted into File2
      if (x >= linesCount1 && y >= linesCount2) {
        return updateList;
      }
    }
  }

  cout << "Indefinite Lines Count" << endl;
  exit(EXIT_FAILURE);
}

void DiffSession::printTable(vector<vector<string>> result) {
  int countLinesUpdated = 1;
  int countLinesPrevious = 1;
  bool printNumberLine = true;

  // Display the table if there is atleast one update in the file
  if (!(this->isSameFile)) {

    cout << "File2 -> " << this->fileName2 << endl;
    cout << "File1 -> " << this->fileName1 << endl;
    cout << endl;

    // Display Column Headers Borders
    if (this->printLineNumber) {
      cout << "+"
           << "-------"
           << "+"
           << "-------";
    }
    cout << "+---+" << string(80, '-') << endl;

    // Display Column Headers Contents
    if (this->printLineNumber) {
      cout << "| "
           << "File2\t"
           << "| "
           << "File1\t";
    }
    cout << "|   | "
         << "Updated File - " << this->fileName2 << endl;

    // Display Column Headers Borders
    if (this->printLineNumber) {
      cout << "+"
           << "-------"
           << "+"
           << "-------";
    }
    cout << "+---+" << string(80, '-') << endl;

    // Display List of Commits
    for (unsigned int i = 0; i < result.size(); i++) {
      if (result[i][0] == "Insert") {
        if (this->printLineNumber) {
          cout << "| " << countLinesUpdated << "\t"
               << "|\t";
        }
        cout << "| + | " << result[i][1] << endl;

        countLinesUpdated++;
      } else if (result[i][0] == "Delete") {
        if (this->printLineNumber) {
          cout << "|\t"
               << "| " << countLinesPrevious << "\t";
        }
        cout << "| - | " << result[i][1] << endl;

        countLinesPrevious++;
      } else if (result[i][0] == "Keep") {
        if (!(this->displayUpdateOnly)) {
          if (this->printLineNumber) {
            cout << "| " << countLinesUpdated << "\t"
                 << "| " << countLinesPrevious << "\t";
          }
          cout << "|   | " << result[i][1] << endl;
        }

        countLinesUpdated++;
        countLinesPrevious++;
      }
    }

    if (this->printLineNumber) {
      cout << "+"
           << "-------"
           << "+"
           << "-------";
    }
    cout << "+---+" << string(80, '-') << endl;
  } else {
    cout << "There are no significant updates between the two files" << endl;
  }
}

string DiffSession::getFileName(string path) {
  int strLength = path.length();
  string name = "";
  for (int i = strLength - 1; i >= 0; i--) {
    if (path[i] == '\\' || path[i] == '/')
      break;
    name = path[i] + name;
  }
  return name;
}

bool DiffSession::strCompare(string line1, string line2, bool ignoreSpace) {
  // To ignore spaces and tabs in the updated files
  if (ignoreSpace) {
    line1.erase(remove_if(line1.begin(), line1.end(), ::isspace), line1.end());
    line2.erase(remove_if(line2.begin(), line2.end(), ::isspace), line2.end());
    return (line1.compare(line2) == 0);
  } else {
    return (line1.compare(line2) == 0);
  }
}
