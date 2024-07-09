#define ll long long

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int _maxi = 0;
int _res = 0;
vector<int> _idList;
ll _preSum[50009] = {};

void ParseIn () {
    int curInt = 0;

    ifstream inFile ("div7.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;

        _idList.push_back(curInt);
    }

    inFile.close();
}

void GenPreSum () {
    _preSum[0] = _idList[0];

    for (int i = 1; i < _maxi; i++) {
        _preSum[i] = _preSum[i-1] + _idList[i];
        _preSum[i-1] %= 7;
    } 

    _preSum[_maxi-1] %= 7;
}

void Core () {
    int firstArr[9] = {};
    memset(firstArr, -1, sizeof(firstArr));

    GenPreSum ();

    for (int i = 0; i < _maxi; i++) {
        cout << _preSum[i] << endl;
        if (firstArr[_preSum[i]] == -1) {firstArr[_preSum[i]] = i;}
        else {_res = max(_res, i-firstArr[_preSum[i]]); cout << firstArr[_preSum[i]] << ", " << i << endl;}
    }
}

void WriteOut () {
    ofstream outFile ("div7.out");

    outFile << _res;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
