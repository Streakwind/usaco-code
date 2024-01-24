

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
	int N = 0;
	int Q = 0;
	int curNum = 0;
	int prevH = 0;
	int prevG = 0;
	int prevJ = 0;
	int a = 0;
	int b = 0;
	vector<int> cowList;
	vector<int> hList = {0};
	vector<int> gList = {0};
	vector<int> jList = {0};

	ifstream inFile ("bcount.in");
	inFile >> N >> Q;

	for (int i = 0; i < N; i++) {inFile >> curNum; cowList.push_back(curNum);}

	for (int i = 0; i < N; i++) {
		if (cowList[i] == 1) {prevH++;}
		if (cowList[i] == 2) {prevG++;}
		if (cowList[i] == 3) {prevJ++;}

		hList.push_back(prevH);
		gList.push_back(prevG);
		jList.push_back(prevJ);
	}

	// for (int i = 0; i < N+1; i++) {
	// 	cout << hList[i] << ", " << gList[i] << ", " << jList[i] << endl;
	// }
	
	ofstream outFile ("bcount.out");
	
	for (int i = 0; i < Q; i++) {
		inFile >> a >> b;

		outFile << hList[b] - hList[a-1] << " ";
		outFile << gList[b] - gList[a-1] << " ";
		outFile << jList[b] - jList[a-1] << endl;
	}

	inFile.close();
	outFile.close();
	
	return 0;
}
