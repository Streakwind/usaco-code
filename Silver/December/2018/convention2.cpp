#define ll long long

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

ll _res = 0;
ll _maxi = 0;
vector<vector<ll>> _curCowList;
ll _startCowPos = 0;

void ParseIn () {
    ll curStart = 0, curTime = 0;
    ll earlyStart = INT32_MAX;

    ifstream inFile ("convention2.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curStart >> curTime;

        _curCowList.push_back({(ll)i, curStart, curTime});

        if (curStart < earlyStart) {_startCowPos = i; earlyStart = curStart;}
    }

    inFile.close();
}

bool CompTime (vector<ll> a, vector<ll> b) { //sort by start
    return a[1] < b[1];
}

vector<ll> ReturnList (vector<ll> listToCopy) {
    return listToCopy;
}

void Core () {
    ll curTime = 0;
    ll amtCow = 0;
    set<vector<ll>> waitingCow;
    vector<ll> curCow;

    sort(_curCowList.begin(), _curCowList.end(), CompTime);

    while (amtCow < _maxi || !waitingCow.empty()) { //will break if all cows in the set and no cows are waiting to be processed
        if (amtCow < _maxi && _curCowList[amtCow][1] <= curTime) {
            waitingCow.insert(_curCowList[amtCow]);

            amtCow++;
        } else if (waitingCow.empty()) {
            curTime = _curCowList[amtCow][1];

            curTime += _curCowList[amtCow][2];

            amtCow++; //counts this as processed because waiting time is 0, can be ignored
        } else {
            curCow = ReturnList(*waitingCow.begin());

            _res = max(_res, curTime - curCow[1]);

            curTime += curCow[2];
            waitingCow.erase(waitingCow.begin());
        }
    }
}

void CWriteOut () {
    ofstream outFile ("convention2.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
