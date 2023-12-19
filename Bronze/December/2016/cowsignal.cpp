#define iF inFile
#define pb push_back


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> _lineList;

int main () {
    int maxi = 0;
    int magnify = 0;
    int maxChar = 0;
    char curChar = '&';
    string resStr = "";
    vector< vector<char>> givenList;
    vector<char> curList;
    vector< vector<char>> resList;

    ifstream inFile ("cowsignal.in");

    iF >> maxi >> maxChar >> magnify;

    for (int i = 0; i < maxi; i++) {
        for (int m = 0; m < maxChar; m++) {
            iF >> curChar;

            curList.pb(curChar);
        }

        givenList.pb(curList);
        curList.clear();
    }

    iF.close();

    for (int i = 0; i < givenList.size(); i++) {
        for (int m = 0; m < givenList[i].size(); m++) {
            for (int n = 0; n < magnify; n++) {curList.pb(givenList[i][m]);}
        }

        for (int n = 0; n < magnify; n++) {resList.pb(curList);}
        curList.clear();
    }

    ofstream outFile ("cowsignal.out");

    for (int i = 0; i < maxi*magnify; i++) {
        for (int m = 0; m < maxChar*magnify; m++) {
            outFile << resList[i][m];
        }

        outFile << endl;
    }
    
    outFile.close();

    return 0;
}
