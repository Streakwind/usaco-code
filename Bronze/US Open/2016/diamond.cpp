

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> _diamondList;
int _diamondArr[100009];
int _maxDiff = 0;
int _maxi = 0;
int _res = 0;

void ParseIn () {
    int solo = 0;

    memset(_diamondArr, 0, sizeof(_diamondArr));
    
    ifstream inFile ("diamond.in");

    inFile >> _maxi >> _maxDiff;

    for (int i = 0; i < _maxi; i++) {
        inFile >> solo;

        _diamondList.push_back(solo);
        _diamondArr[solo]++;
    }

    inFile.close();
}

bool leastToGreat (int a, int b) {
    return a < b;
}

void Core () {
    int cc = 0;
    int startI = 0;
    int endI = 0;

    sort(_diamondList.begin(), _diamondList.end(), leastToGreat); 

    startI = _diamondList[0];
    endI = _diamondList[_diamondList.size()-1];

    endI -= _maxDiff;

    if (endI < 0) {
        _res = _maxi;

        return;
    }

    //cout << "[" << startI << ", " << endI << "]" << endl;

    for (int i = startI; i < endI + 1; i++) { //we want to include endI
        for (int m = i; m < i + _maxDiff + 1; m++) { //include i + _maxDiff
            cc += _diamondArr[m];
        }

        if (cc > _res) {
            _res = cc;
        }

        cc = 0;
    }
}

void WriteOut () {
    ofstream outFile ("diamond.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();
    
    return 0;
}
