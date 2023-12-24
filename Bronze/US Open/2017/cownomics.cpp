

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int _res = 0;
vector<string> _spotList;
vector<string> _plainList;
int _maxi = 0;
int _letters = 0;

void ParseIn () {
    string myStr = "";

    ifstream inFile ("cownomics.in");

    inFile >> _maxi >> _letters;

    for (int i = 0; i < _maxi; i++) {
        inFile >> myStr;

        _spotList.push_back(myStr);
    }
    
    for (int i = 0; i < _maxi; i++) {
        inFile >> myStr;

        _plainList.push_back(myStr);
    }

    inFile.close();
}

void Core () {
    map<char, int> strandMap;

    for (int i = 0; i < _letters; i++) {
        for (int m = 0; m < _maxi; m++) {
            strandMap[_spotList[m][i]] = 1;
        }

        for (int m = 0; m < _maxi; m++) {
            if (strandMap.count(_plainList[m][i]) != 0) { //it exists
                break;
            }

            if (m == _maxi - 1) {
                _res++;
            }
        }

        strandMap.clear();
    }
}

void WriteOut () {
    ofstream outFile ("cownomics.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
