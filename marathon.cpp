

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _checkAmount = 0;
vector<int> _xList;
vector<int> _yList;
int _length = 0;
int _skipL = 0;

void ParseIn () {
    int curInt = 0;
    
    ifstream inFile("marathon.in");
    
    inFile >> _checkAmount;
    
    for (int i = 0; i < _checkAmount; i++) {
        inFile >> curInt;
        
        _xList.push_back(curInt);
        
		inFile >> curInt;
        
		_yList.push_back(curInt);
    }
    
    cout << endl;
}

int GetAbsolute (int n) {
    if (n < 0) {
        return n * -1;
    }
	
	else {
        return n;
    }
}

void MaraLength () {
    int curInt = 0;

    for (int i = 0; i < _checkAmount - 1; i++) {
        curInt = GetAbsolute(_xList[i] - _xList[i+1]) + GetAbsolute(_yList[i] - _yList[i+1]);
        
        _length = _length + curInt;
    }
}

void findSkip () {
    int skip = 0;

    for (int i = 1; i <_checkAmount - 1;i ++) {
        int LPN = GetAbsolute(_xList[i - 1] - _xList[i + 1]) + GetAbsolute(_yList[i - 1]- _yList[i + 1]);
        int LPC = GetAbsolute(_xList[i - 1] - _xList[i]) + GetAbsolute(_yList[i - 1]- _yList[i]);
        int LCN = GetAbsolute(_xList[i + 1] - _xList[i]) + GetAbsolute(_yList[i + 1]- _yList[i]);
        
        skip = LCN + LPC - LPN;
        
        if (skip > _skipL) {
            _skipL = skip;
        }
    }
    
    ofstream outFile("marathon.out");
    
    outFile << _length - _skipL;
}

void CoreOut () {
    MaraLength();
    
    findSkip();
}

int main () {
    ParseIn();
    
    CoreOut();
}
