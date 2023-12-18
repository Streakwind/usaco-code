

#include <iostream>
#include <fstream>

using namespace std;

int _roadTab[109];
int _bessieTab[109];
int _res = 0;

void ParseIn () {
    int roadMaxi = 0;
    int bessieMaxi = 0;
    int limit = 0;
    int start = 0;
    int dis = 0;

    ifstream inFile ("speeding.in");

    inFile >> roadMaxi >> bessieMaxi;

    for (int i = 0; i < roadMaxi; i++) {
        inFile >> dis >> limit;
        
        for (int m = start; m < dis+start; m++) {
            _roadTab[m] = limit;
        }

        start += dis;
    }

    start = 0;

    for (int i = 0; i < bessieMaxi; i++) {
        inFile >> dis >> limit;
        
        for (int m = start; m < dis+start; m++) {
            _bessieTab[m] = limit;
        }

        start += dis;

        //cout << start << endl;
    }
}

void Core () {
    int curRes = 0;

    for (int i = 0; i < 100; i++) {
        //cout << "road->" << _roadTab[i] << " bessie->" << _bessieTab[i] << endl;

        if (_bessieTab[i] > _roadTab[i]) {
            curRes = _bessieTab[i] - _roadTab[i];

            if (curRes > _res) {
                _res = curRes;
            }
        }
    }
}

void WriteOut () {
    ofstream outFile ("speeding.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
