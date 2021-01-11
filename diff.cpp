/****************************************************************************
*Filename:          diff.cpp
*Author:            Shehab Hosny
*Date:	            1/11/2021
*Version:           1.0
*Description:       MED Qualification Task
*Myers Algorithm    http://www.xmailserver.org/diff2.pdf
****************************************************************************/

#include <tuple>
#include <string>
#include <vector>
#include <fstream> 
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
* DiffSession
* This class provides the user a single session  (as in Windows FC diff tool) to
* get the updates in two file versions. The user must pass atleast two arguments
* in addition to the exe call. If any of these arguments are missing the program
* will terminate. However, the user may add up to three additional arguments for 
* additional diff options indicated in the class constructor.
*/
class DiffSession {
public:

    // Start a single session for files comparison
    DiffSession(int argc, char** argv) {

        string argElement;

        this->filePath1 = argv[1];  // Old version file
        this->filePath2 = argv[2];  // New version file
        this->fileName1 = getFileName(this->filePath1);
        this->fileName2 = getFileName(this->filePath2);

        // Assign additional options for the current session
        for (int i = 3; i < argc; i++) {

            argElement = argv[i];

            if (argElement == "/N") {
                this->printLineNumber = true;
            }

            if (argElement == "/W") {
                this->ignoreWhiteSpaces = true;
            }

            if (argElement == "/A") {
                this->displayUpdateOnly = true;
            }
        }
    }

    // Get the diff and Display it for the running session
    void showDiff() {

        vector<string> linesFile1 = getLinesFromFile(this->filePath1),
                       linesFile2 = getLinesFromFile(this->filePath2);

        vector<vector<string>> diff = getDiff(linesFile1, linesFile2);

        printTable(diff);
    }

    // Load the input file into a vector of separate lines
    vector<string> getLinesFromFile(string path) {

        vector<string> lines;
        string singleLine;
        fstream newfile;

        newfile.open(path);

        // Check that the specified file can open successfully
        if (newfile.is_open()) {

            while (getline(newfile, singleLine)) {
                lines.push_back(singleLine);
            }
            newfile.close();
        }

        // Terminate the program
        else {
            cout << "Can not open the specified directory - No such file or folder" << endl;
            exit(EXIT_FAILURE);
        }

        return lines;
    }

    // An implementation of Myers Diff algorithm
    vector<vector<string>> getDiff(vector<string> linesFile1, vector<string> linesFile2) {
        
        // Myers' graph coordinates
        int x, y, xPrevious;
        
        int linesCount1     = linesFile1.size(),
            linesCount2     = linesFile2.size(),
            totalLinesCount = linesCount1 + linesCount2;

        // Hashmap to backtrack Myers' graph and get the best path of commits
        unordered_map<int, tuple<int, vector<vector<string>>>> mapGrid;

        // Commit history list with all Keeps, Insertions and Deletions
        vector<vector<string>> updateList;

        // Used to access the tuple elements
        const int xCoordinate = 0,
                  lastUpdate  = 1;

        for (int d = 0; d <= totalLinesCount; d++) {

            for (int k = -d; k <= d; k += 2) {

                // checkPath checks which of the 2 previous k values has the largest value of x
                bool checkPath = get<xCoordinate>(mapGrid[k - 1]) < get<xCoordinate>(mapGrid[k + 1]),
                     moveDown  = (k == -d) || (k != d && checkPath);

                // This is to add a line from the updated file
                if (moveDown) {
                    updateList = get<lastUpdate>(mapGrid[k + 1]);
                    xPrevious  = get<xCoordinate>(mapGrid[k + 1]);
                    x = xPrevious;
                }

                // moveRight - This is to delete a line from the old file
                else {
                    updateList = get<lastUpdate>(mapGrid[k - 1]);
                    xPrevious  = get<xCoordinate>(mapGrid[k - 1]);
                    x = xPrevious + 1;
                }

                y = x - k;

                // Update the history list with an Insertion
                if ((1 <= y && y <= linesCount2) && (moveDown)) {
                    updateList.push_back({ "Insert", linesFile2[y - 1] });
                    if (this->isSameFie) this->isSameFie = false;
                }

                // Update the history list with a Deletion
                else if (1 <= x && x <= linesCount1) {
                    updateList.push_back({ "Delete", linesFile1[x - 1] });
                    if (this->isSameFie) this->isSameFie = false;
                }

                // Handle similar lines in both files
                while ((x < linesCount1) && (y < linesCount2) &&
                       (strCompare(linesFile1[x], linesFile2[y], this->ignoreWhiteSpaces))) {
                    x++;
                    y++;
                    updateList.push_back({ "Keep", linesFile1[x - 1] });
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

    // Display the diff table including all commits
    void printTable(vector<vector<string>> result) {

        int countLinesUpdated  = 1;
        int countLinesPrevious = 1;
        bool printNumberLine   = true;

        // Display the table if there is atleast one update in the file
        if (!(this->isSameFie)) {

            cout << "File1 -> " << this->fileName2 << endl;
            cout << "File2 -> " << this->fileName1 << endl;
            cout << endl;

            // Display Column Headers
            if (this->printLineNumber) cout << "+" << "-------" << "+" << "-------";
            cout << "+---+" << "--------------------------------------------------------------------------" << endl;

            if (this->printLineNumber) cout << "| " << "File1\t" << "| " << "File2\t";
            cout << "|   | " << "Updated File - " << this->fileName2 << endl;

            if (this->printLineNumber) cout << "+" << "-------" << "+" << "-------";
            cout << "+---+" << "--------------------------------------------------------------------------" << endl;

            // Display List of Commits
            for (unsigned int i = 0; i < result.size(); i++) {

                if (result[i][0] == "Insert") {
                    if (this->printLineNumber) cout << "| " << countLinesUpdated << "\t" << "|\t";
                    cout << "| + | " << result[i][1] << endl;

                    countLinesUpdated++;
                }
                else if (result[i][0] == "Delete") {
                    if (this->printLineNumber)cout << "|\t" << "| " << countLinesPrevious << "\t";
                    cout << "| - | " << result[i][1] << endl;

                    countLinesPrevious++;
                }
                else if (result[i][0] == "Keep" ) {
                    if (!(this->displayUpdateOnly)) {
                        if (this->printLineNumber) cout << "| " << countLinesUpdated << "\t" << "| " << countLinesPrevious << "\t";
                        cout << "|   | " << result[i][1] << endl;
                    }

                    countLinesUpdated++;
                    countLinesPrevious++;
                }
            }

            if (this->printLineNumber) cout << "+" << "-------" << "+" << "-------";
            cout << "+---+" << "--------------------------------------------------------------------------" << endl;
        }

        else {
            cout << "There are no significant updates between the two files" << endl;
        }
    }

private:

    string filePath1, filePath2, fileName1, fileName2;
    bool printLineNumber   = false,
         ignoreWhiteSpaces = false,
         displayUpdateOnly = false,
         isSameFie         = true;

    // Extracts file name from file path
    string getFileName(string path) {
        int strLength = path.length();
        string name = "";
        for (int i = strLength - 1; i >= 0; i--) {
            if (path[i] == '\\') break;
            name = path[i] + name;
        }
        return name;
    }

    // Check if two strings are the same whether whitespaces are included or not
    bool strCompare(string line1, string line2, bool ignoreSpace) {

        // To ignore spaces and tabs in the updated files
        if (ignoreSpace) {
            line1.erase(remove_if(line1.begin(), line1.end(), ::isspace), line1.end());
            line2.erase(remove_if(line2.begin(), line2.end(), ::isspace), line2.end());
            return (line1.compare(line2) == 0);
        }
        else {
            return (line1.compare(line2) == 0);
        }
    }
};

int main(int argc, char** argv) {
    
    cout << 
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
        "+-------------------------------------------------+\n" << endl;


    if (argc < 3) {
        cout << "Insufficient number of file specifications" << endl;
        return 0;
    }

    DiffSession session(argc, argv);

    session.showDiff();

    return 0; 
}