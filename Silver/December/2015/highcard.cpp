

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi = 0;
int _res = 0;
vector<int> _eCards; //elsie
vector<int> _bCards; //bessie

void ParseIn () {
    int curInt = 0;

    ifstream inFile ("highcard.in");

    inFile >> _maxi;

    int _takenNum[_maxi*2 + 1] = {};

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;

        _eCards.push_back(curInt);
        _takenNum[curInt]++;
    }

    for (int i = 1; i < _maxi*2+1; i++) {
        if (_takenNum[i] != 1) {_bCards.push_back(i);}
    }

    inFile.close();
}

bool CompDown (int a, int b) {
    return a > b;
}

void Core () {
    int curB = 0;
    int curE = 0;

    sort(_eCards.begin(), _eCards.end(), CompDown);
    sort(_bCards.begin(), _bCards.end(), CompDown);

    while (curB < _maxi && curE < _maxi) {
        cout << _bCards[curB] << ", " << _eCards[curE] << endl;

        if (_bCards[curB] > _eCards[curE]) {
            curB++, curE++;
            _res++;
        } else {
            curE++;
        }
    }
}

void CWriteOut () {
    ofstream outFile ("highcard.out");

    outFile << _res << endl;
    
    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
