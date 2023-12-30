#define CPL cowPosList
//this is the first usaco code I wrote on my ipad... it's kind of bad I know
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int curInt = 0;
	vector<int> cowPosList;
	
	ifstream inFile ("herding.in");
	
	while (inFile >> curInt) {
		cowPosList.push_back(curInt);
	}
	
	inFile.close();
	
	sort(cowPosList.begin(), cowPosList.end());
	
	int min, max = 0;
	
	
//	if (cowPosList[2]-cowPosList[1] > cowPosList[1]-cowPosList[0]) {
//		max = CPL[2] - CPL[1];
//		max -= 1;
		
//		min = CPL[1] - CPL[0];
//		min -= 1;
//	} else{
//		max = CPL[1] - CPL[0];
//		max -= 1;
		
//		min = CPL[2] - CPL[1];
//		min -= 1;
//	}
	min = 2;
	
	if (CPL[2] - CPL[1] == 1 && CPL[1] - CPL[0] == 1) {
		min = 0;
	}
	if (CPL[2]-CPL[1] == 2 || CPL[1] - CPL[0] == 2) {
		min = 1;
	}
	
	if (CPL[2] - CPL[1] > CPL[1] - CPL[0]) {max = CPL[2] - CPL[1];} 
	else{max = CPL[1] - CPL[0];}
	
	max -= 1;
	
	ofstream outFile ("herding.out");
	
	outFile << min << endl;
	outFile << max << endl;
	
	outFile.close();
	
	return 0;
}