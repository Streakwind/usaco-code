

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Phrase {
	vector<string> _wordList;	
};

int _lim = 0;
vector <string> _oriList;
vector<Phrase> _resList; 

void ParseIn () {
	int maxi = 0;
	string curStr = "Error";
	
	ifstream inFile ("word.in"); 
	
	inFile >> maxi >> _lim;
	
	for (int i = 0; i < maxi; i++) {
		inFile >> curStr;
		
		_oriList.push_back(curStr);	
	}
	
	inFile.close();
}

void DisplayPhraseList (vector <Phrase> theList) {
	Phrase pSolo;
	string solo;
	vector <string> curList;
	
	for (int i = 0; i < theList.size (); i++) {
		pSolo = theList[i];
		curList = pSolo._wordList;
		
		for (int m = 0; m < curList.size(); m++) {
			solo = curList[m];
			
			cout << solo;
			
			if (m == curList.size() - 1) {
				continue;
			}
			cout << " ";
		}
		cout << endl;
	}

}

void FilePhraseList (vector <Phrase> theList) {
	Phrase pSolo;
	string solo;
	vector <string> curList;
	
	ofstream outFile ("word.out");
	
	for (int i = 0; i < theList.size (); i++) {
		pSolo = theList[i];
		curList = pSolo._wordList;
		
		for (int m = 0; m < curList.size(); m++) {
			solo = curList[m];
			
			outFile << solo;
			
			if (m == curList.size() - 1) {
				continue;
			}
			outFile << " ";
		}
		outFile << endl;
	}
	
	outFile.close();
}

void Core () {
	Phrase pSolo;
	string solo = "Error";
	int curLength = 0;
	vector<string> curList;
	
	for (int i = 0; i < _oriList.size(); i++) {
		solo = _oriList[i];
		
		curLength += solo.length();
		
		if (curLength > _lim) {
			pSolo._wordList = curList;
			_resList.push_back(pSolo);
			
			curList.clear();
			curLength = 0;
			i--;
			
			continue;
		}
		curList.push_back (solo);	
	}
	
	if (curList.size() > 0) {
		pSolo._wordList = curList;
		_resList.push_back(pSolo);
	}
}

void WriteOut () {
	FilePhraseList (_resList);
}

int main () {
	ParseIn ();
	Core ();
	WriteOut ();
	
	return 0;	
}
