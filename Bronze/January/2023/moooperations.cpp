

#include <iostream>
#include <vector>

using namespace std;

vector<string> _strList;
vector<int> _resList;
int _maxi = 0;

void CParseIn () {
    string curStr = "parse error";

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        cin >> curStr;

        _strList.push_back(curStr);
    }
}

void Core () {
    string strOp = "error in core";
    int curRes = INT32_MAX;
    int toAdd = 0;

    for (int i = 0; i < _maxi; i++) {
        toAdd = _strList[i].length() - 3; //3 is length of MOO
        curRes = INT32_MAX;

        for (int m = 0; m < _strList[i].length() - 2; m++) {
            if (_strList[i].length() < 3) {break;}

            strOp = _strList[i].substr(m, 3);
            //cout << strOp << endl;
            
            if (strOp[1] == 'M') {curRes = min(curRes, INT32_MAX);}
            if (strOp == "MOO") {curRes = min(curRes, 0);}
            if (strOp == "MOM") {curRes = min(curRes, 1);}
            if (strOp == "OOO") {curRes = min(curRes, 1);}
            if (strOp == "OOM") {curRes = min(curRes, 2);}
        }

        if (_strList[i].length() > 3 && curRes != INT32_MAX) {curRes += toAdd;}
        if (curRes == INT32_MAX) {curRes = -1;}

        _resList.push_back(curRes);
    }
}

void CWriteOut () {
    for (int i = 0; i < _resList.size(); i++) {
        cout << _resList[i] << endl;
    }
}

int main () {
    CParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}

