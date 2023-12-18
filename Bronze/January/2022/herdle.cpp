

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// vector<string> _ansList;
// vector<string> _gesList;
string _ans = "";
string _ges = "";
int _ycc = 0;
int _gcc = 0;

void ParseIn () {
    string solo = "";

    ifstream inFile ("herdle.in");

    for (int i = 0; i < 3; i++) {
        inFile >> solo;

        _ans += solo;
    }
    
    for (int i = 0; i < 3; i++) {
        inFile >> solo;

        _ges += solo;
    }

    inFile.close();
}

void CParseIn () {
    string solo = "";

    for (int i = 0; i < 3; i++) {
        cin >> solo;

        _ans += solo;
    }
    
    for (int i = 0; i < 3; i++) {
        cin >> solo;

        _ges += solo;
    }
}

void FindGreen () {
    for (int i = 0; i < _ans.size(); i++) {
        if (_ans[i] == _ges[i]) {
            //green
            _gcc++;
            _ans[i] = '0';
            _ges[i] = '0';
        }
    }
}

void FindYellow () {
    char solo = '&';

    for (int i = 0; i < _ans.size(); i++) {
        solo = _ans[i];

        for (int m = 0; m < _ans.size(); m++) {
            if (solo == '0') {
                break;
            }

            if (solo == _ges[m]) {
                _ycc++;
                _ges[m] = '0';
                break;
            }
        }
    }
}

void Core () {
    FindGreen();

    //cout << _ans << " " << _ges << endl;

    FindYellow();

    //cout << _ans << " " << _ges << endl;
}

void CWriteOut () {
    cout << _gcc << endl;
    cout << _ycc << endl;
}

int main () {
    //ParseIn ();
    CParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
