

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

vector<string> _myList;
int _maxi = 0;
int _res = 0;

void ParseIn () {
    string city = "";
    string resStr = "";
    string state = "";

    ifstream inFile ("citystate.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> city >> state;

        resStr += city[0];
        resStr += city[1];

        resStr += state;

        _myList.push_back(resStr);

        //cout << resStr << endl;

        resStr = "";
    }

    inFile.close();
}

string FlipStr (string oriStr) {
    string res = "";
    
    //ex: MIFL
    res += oriStr[2]; //F
    res += oriStr[3]; //L

    res += oriStr[0]; //M
    res += oriStr[1]; //I

    return res;
}

void Core () {
    map<string, int> cityState;
    string target = "";
    string stateOne = "";
    string stateTwo = "";

    for (int i = 0; i < _maxi; i++) {
        target = FlipStr(_myList[i]);

        //cout << target << ", " << _myList[i] << endl;

        if (cityState.count(target)) { //if it exists
            stateOne += _myList[i][2];
            stateOne += _myList[i][3];

            stateTwo += target[2];
            stateTwo += target[3];

            //cout << "state->" << stateOne << stateTwo << endl;

            if (stateOne != stateTwo) { //different state check
                //cout << target << ", " << _myList[i] << "->" << cityState[target] << endl;
                _res += cityState[target];
            }

            stateOne = "";
            stateTwo = "";
        }

        cityState[_myList[i]]++;
    }
}

void WriteOut () {
    ofstream outFile ("citystate.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
