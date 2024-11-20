

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int _maxi = 0;

vector<int> countLetters (string myStr) {
    vector<int> resList(26);

    for (int i = 0; i < myStr.length(); i++) {
        resList[myStr[i] - 'a']++;
    }

    return resList;
}

int main () {
	vector<pair<string, string>> myList;

	ifstream inFile ("blocks.in");

	inFile >> _maxi; myList.resize(_maxi);

    //cout << _maxi << endl;

	for (int i = 0; i < _maxi; i++) {
		inFile >> myList[i].first >> myList[i].second;
	}

	inFile.close();

    //cout << "!" << endl;

    vector<int> _resList(26);

    for (int i = 0; i < _maxi; i++) {
        vector<int> firstWord = countLetters(myList[i].first);
        vector<int> secondWord = countLetters(myList[i].second);

        for (int m = 0; m < 26; m++) {_resList[m] += max(firstWord[m], secondWord[m]);}
    }

    ofstream outFile ("blocks.out");

    for (int i = 0; i < 26; i++) {
        outFile << _resList[i] << endl;
    }

    outFile.close();

    //cout << "!" << endl;

	return 0;
}
