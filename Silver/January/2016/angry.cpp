

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int _targetNum = 0;
int _cowNum = 0;

vector<int> _targetList;

int _res = 0;

void ParseIn () {
    ifstream inFile ("angry.in");

    inFile >> _targetNum >> _cowNum;

    _targetList.resize(_targetNum);

    for (int i = 0; i < _targetNum; i++) {inFile >> _targetList[i];}

    inFile.close();
}

//count amount of intervals needed for radius*2 to affect all cows
bool isValid (int radius) {
    //total blocks affected: radius * 2
    int curMax = INT8_MIN;
    int intervals = 0;

    for (int i = 0; i < _targetList.size(); i++) {
        //fits in the radius
        if (_targetList[i] <= curMax) {continue;}

        //otherwise, start a new interval
        intervals++;
        curMax = _targetList[i] + radius*2;
    }

    return (intervals <= _cowNum);
}

void Core () {
    sort(_targetList.begin(), _targetList.end());

    int l, m, r;

    l = 0;
    r = _targetList.size()-1;

    while (l < r) {
        m = l + (r-l)/2;

        if (isValid(m)) {r = m;}
        else {l = m+1;}
    }

    _res = l;
}

void WriteOut () {
    ofstream outFile ("angry.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
