

#include <iostream>
#include <fstream>

using namespace std;

int _res = 0;
int _fence[109];

void ParseIn () {
    int startNum = 0;
    int endNum = 0;

    ifstream inFile ("paint.in");

    inFile >> startNum >> endNum;

    for (int i = startNum; i < endNum; i++) {
        _fence[i] = 1;
    }

    inFile >> startNum >> endNum;

    for (int i = startNum; i < endNum; i++) {
        _fence[i] = 1;
    }

    inFile.close();
}

void Core () {
    for (int i = 0; i < 109; i++) {
        if (_fence[i] == 1) {
            _res++;
        }
    }
}

void WriteOut () {
    ofstream outFile ("paint.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
