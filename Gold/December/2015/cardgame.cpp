

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi = 0;
int _res = 0;
vector<int> _eCardsPre; //elsie, before half
vector<int> _eCardsPost; //elsie, after half
vector<int> _bCards; //bessie

void ParseIn () {
    int curInt = 0;

    ifstream inFile ("cardgame.in");

    inFile >> _maxi;

    int _takenNum[_maxi*2 + 1] = {};

    for (int i = 0; i < _maxi/2; i++) {
        inFile >> curInt;

        _eCardsPre.push_back(curInt);
        _takenNum[curInt]++;
    }

    for (int i = _maxi/2; i < _maxi; i++) {
        //cout << i << endl; 

        inFile >> curInt;
        
        //cout << curInt << endl;

        _eCardsPost.push_back(curInt);
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

// bool CompUp (int a, int b) {
//     return a < b;
// }

void Core () {
    int curB = 0;
    int curE = 0;

    sort (_eCardsPre.begin(), _eCardsPre.end(), CompDown);
    sort (_bCards.begin(), _bCards.end(), CompDown);

    sort (_eCardsPost.begin(), _eCardsPost.end(), CompDown);

    while (curB < _maxi/2 && curE < _maxi/2) {
        cout << _bCards[curB] << ", " << _eCardsPre[curE] << endl;

        if (_bCards[curB] > _eCardsPre[curE]) {
            curB++, curE++;
            _res++;
        } else {
            curE++;
        }
    }

    curE = 0;

    while (curB < _maxi && curE < _maxi/2) {
        cout << _bCards[curB] << ", " << _eCardsPost[curE] << endl;

        if (_bCards[curB] < _eCardsPost[curE]) {
            curB++, curE++;
            _res++;
        } else {
            curB++;
        }
    }
}

void CWriteOut () {
    ofstream outFile ("cardgame.out");

    outFile << _res << endl;
    
    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
