

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int _maxTime = 0;
int _maxi = 0;
vector<int> _cowList; //stores time it takes for each cow
int _res = 0;

void ParseIn () {
    int curInt = 0;

    ifstream inFile ("cowdance.in");

    inFile >> _maxi >> _maxTime;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;

        _cowList.push_back(curInt);
    }

    inFile.close();
}

bool testCurK (int curK) {
    int nextElement = 0;
    priority_queue<int, vector<int>, greater<int>> curStage;

    for (int i = 0; i < curK; i++) {curStage.push(_cowList[i]);}

    for (int i = curK; i < _maxi; i++) {
        cout << _cowList[i] << ", " << curStage.top() << endl;

        nextElement = _cowList[i] + curStage.top(); //total time is added

        if (nextElement > _maxTime) {
            cout << curK << "->" << nextElement << " i->" << i << endl; 
            return false;
        }
        
        curStage.pop();
        curStage.push(nextElement);
    }
    
    cout << curK << "->true" << endl;

    return true;
}

void Core () {
    int curK = 0; 
    int L = 1, R = _maxi;//current group size at max is maxi, min is 1
    bool doesWork = false;

    _res = _maxi; //given K=N always works

    while (L < R+1) {
        curK = L + (R-L)/2;

        doesWork = testCurK (curK);

        if (doesWork) {R = curK-1; _res = min(_res, curK);}
        else {L = curK+1;}
    }
}

void WriteOut () {
    ofstream outFile ("cowdance.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
