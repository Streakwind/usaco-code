

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _trees = 0;
int _baskets = 0;
int _res = 0;
int _maxNum = 0;
int _mod = 0;
vector<int> _treeList;

void ParseIn () {
    int curInt = 0;

    ifstream inFile ("berries.in");

    inFile >> _trees >> _baskets;

    for (int i = 0; i < _trees; i++) {
        inFile >> curInt;

        _treeList.push_back(curInt);

        _maxNum = max(_maxNum, curInt);
    }

    inFile.close();
}

bool CompDownMod (int a, int b) {
    return a%_mod > b%_mod;
}

void Core () {
    int basketAmt = 0;
    int leftovers = 0;

    for (int i = 1; i < _maxNum+1; i++) {
        basketAmt = 0;
        leftovers = 0;

        for (int m = 0; m < _trees; m++) {basketAmt += _treeList[m] / i;}

        if (basketAmt < _baskets/2) {continue;} //not enough baskets
        if (basketAmt > _baskets-1) {_res = max(_res, (_baskets/2) * i); continue;} //enough baskets so both cows have same amount
        _mod = i;
        sort (_treeList.begin(), _treeList.end(), CompDownMod);

        leftovers = (basketAmt - _baskets/2) * i;
        
        for (int m = 0; m < _trees && m+basketAmt < _baskets; m++) {
            leftovers += _treeList[m]%_mod;
        }

        _res = max(_res, leftovers);

        //cout << i << "->" << _res << endl;
    }

    
}

void CWriteOut () {
    ofstream outFile ("berries.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
