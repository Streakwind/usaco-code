

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
	int maxi = 0;
	int curInt = 0;
	int res = 0;
	vector<int> numList;
	
	ifstream inFile ("sleepy.in");
	
	inFile >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		inFile >> curInt;
		
		numList.push_back(curInt);
	}
	
	inFile.close();
	
	res = maxi - 1;
	
	for (int i = maxi-2; i > -1; i--) {
		if (numList[i] < numList[i+1]) {res = i; continue;}
		break;
	}
	
	ofstream outFile ("sleepy.out");
	
	outFile << res << endl;
	
	outFile.close();
	
	return 0;
}