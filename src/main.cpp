#include "diff.h"

int main(int argc, char** argv)
{

    cout << Starting_MSG << endl;

    // Check for the minimum number of arguments required
    if (argc < 3) {
        cout << "Insufficient number of file specifications" << endl;
        return 0;
    }

    // Start a single session for files comparison
    DiffSession session(argc, argv);

    // Get the diff and Display it for the running session
    session.showDiff();

    return 0;
}
