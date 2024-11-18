

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int _maxi = 0;
int _maxBus = 0;
int _maxSize = 0;
int _res = 0;

vector<int> _cowList;

void ParseIn () {
    int curInt = 0;

    ifstream inFile ("convention.in");

    inFile >> _maxi >> _maxBus >> _maxSize;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;

        _cowList.push_back(curInt);
    }

    inFile.close();
}

bool isValid (int maxTime) {
    int i = 0;
    int busFilled = 0;
    int firstI = 0;

    while (i < _maxi) {
        //cout << _cowList[i] << ", " << _cowList[firstI] << "->" << i << ", " << firstI << endl;

        if (i == firstI) {busFilled++;} //cout << "bus" << endl;

        if (_cowList[i] - _cowList[firstI] > maxTime) {
            firstI = i;

        } else if (i - firstI + 1 == _maxSize) {
            firstI = ++i;
        } else {
            i++;
        }
    }
    
    return (busFilled < _maxBus + 1);
}

void Core () {
    int left = 0, mid = 0, right = 0;

    sort(_cowList.begin(), _cowList.end());

    right = _cowList[_maxi - 1] - _cowList[0];

    while (right > left) {
        mid = left + (right-left) / 2;

        //cout << "[" << left << ", " << mid << ", " << right << "]" << endl;

        if (isValid(mid)) {
            right = mid;
        } else {
            left = mid+1;
        }
    }

    _res = left;
}

void WriteOut () {
    ofstream outFile ("convention.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
