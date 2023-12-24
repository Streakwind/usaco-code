

#include <iostream>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

vector<string> _spotList;
vector<string> _plainList;
int _maxi = 0;
int _letters = 0;
int _res = 0;

void ParseIn () {
    string genome;

    //ifstream inFile ("infile.in");
    ifstream inFile ("cownomics.in");

    inFile >> _maxi >> _letters;

    for (int i = 0; i < _maxi; i++) {
        inFile >> genome;

        _spotList.push_back(genome);
    }

    for (int i = 0; i < _maxi; i++) {
        inFile >> genome;

        _plainList.push_back(genome);
    }

    inFile.close();
}

void Core () {
    map<string, int> strandMap;
    string key = "";
    int cc = 0;

    for (int i = 0; i < _letters; i++) {
        for (int m = i+1; m < _letters; m++) {
            for (int j = m+1; j < _letters; j++) {
                for (int k = 0; k < _maxi; k++) {
                    key = _spotList[k][i];
                    key += _spotList[k][m];
                    key += _spotList[k][j];

                    //cout << key << endl;

                    strandMap[key] = 1;
                }

                for (int k = 0; k < _maxi; k++) {
                    key = _plainList[k][i];
                    key += _plainList[k][m];
                    key += _plainList[k][j];

                    //cout << key << endl;

                    if (strandMap.find(key) != strandMap.end()) { //exists
                        //cout << key << endl;
                        break;
                    }

                    if (k == _maxi - 1) {
                        _res++;
                    }   
                }

                // if (cc == _maxi) {
                //     cout << "yay" << endl;
                //     _res++;
                // }

                strandMap.clear();
                cc = 0;
            }
        }
    }
}

void WriteOut () {
    //ofstream outFile ("outfile.out");
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
