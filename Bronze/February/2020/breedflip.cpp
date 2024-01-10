

#include <iostream>
#include <fstream>

using namespace std;

int main () {
    int maxi = 0;
    string a = "";
    string b = "";
    string resStr = "";
    int res = 0;
    string curStr = "";

    ifstream inFile("breedflip.in");

    inFile >> maxi >> a >> b;
    
    inFile.close();

    a+= 'G';
    b+='G';

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {resStr+='1';}
        if (a[i] == b[i]) {resStr+='0';}
    }

    for (int i = 1; i < resStr.length(); i++) {
        curStr = resStr[i-1];
        curStr += resStr[i];

        if (curStr == "10") {res++;}
    }

    ofstream outFile ("breedflip.out");

    outFile << res << endl;

    outFile.close();

    return 0;
}
