#define pb push_back

#include <iostream>
#include <fstream>

using namespace std;

const int MAXCOW = 1009;

int _barnGrid[MAXCOW][MAXCOW];

int _maxi = 0; //N
int _optimalNum = 0; //K

int _res = 0;

void ParseIn () {
    int startX = 0, startY = 0;
    int endX = 0, endY = 0;

    ifstream inFile ("paintbarn.in");

    inFile >> _maxi >> _optimalNum;
    
    for (int i = 0; i < _maxi; i++) {
        inFile >> startX >> startY >> endX >> endY;

        for (int m = startY; m < endY; m++) {
            _barnGrid[m][startX]++;
            _barnGrid[m][endX]--;
        }
    }

    inFile.close();
}

void Core () {
    int curSum = 0;

    for (int i = 0; i < MAXCOW; i++) {
        for (int m = 0; m < MAXCOW; m++) {
            curSum += _barnGrid[i][m];
            
            if (curSum == _optimalNum) {_res++;}
        }
    }
}

void WriteOut () {
    ofstream outFile ("paintbarn.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
