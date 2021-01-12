#include "DiffCpp/diff.h"

using namespace std;

int main(int argc, char** argv) {

    cout << Starting_MSG << endl;

    if (argc < 3) {
        cout << "Insufficient number of file specifications" << endl;
        return 0;
    }

    DiffSession session(argc, argv);

    session.showDiff();

    return 0;
}
