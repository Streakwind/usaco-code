//this was my first contest code and first problem solved in contest!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> _myList;
int _A = 2;
int _B = 0;
int _C = 0;
 

void ParseIn () {
	int num1 = 0;
	
	for (int i = 0; i < 7; i++) {
		cin >> num1;
			
		
		_myList.push_back(num1);
		
	//	cout << _myList[i];	
	}
	
}

bool CompRubenIntUp (int one, int two) {
	return one < two;	
}

void FindC () {
	
	for (int i = 0; i < _myList.size(); i++) {
		if (_A + _B + _myList[1] == _myList[i] && _myList[1] >= _B) {
			_C = _myList[1];
			break;
		}
	
		if (_A + _B + _myList[2] == _myList[i] && _myList[2] >= _B) {
			_C = _myList[2];
			break;
		}
	
		if (_A + _B + _myList[3] == _myList[i] && _myList[3] >= _B) {
			_C = _myList[3];
			break;
		}
	
		if (_A + _B + _myList[4] == _myList[i] && _myList[4] >= _B) {
			_C = _myList[4];
			break;
		}
	
		if (_A + _B + _myList[5] == _myList[i] && _myList[5] >= _B) {
			_B = _myList[5];
			break;
		}
	}

}

void WhatIf () {
		
	if (_myList[6] > 0) {
		_C = _myList[6];	
	}
		
}
void Core () {
	sort (_myList.begin(), _myList.end(), CompRubenIntUp);
	_A = _myList[0];
	_B = _myList[1];
	int sum = _A + _B;
	

	_C = _myList[6] - sum;
	
//	FindC ();
	
	if (_myList[0] + _myList[1] + _myList[2] + _myList[3] + _myList[4] + _myList[5] == 0) {
		WhatIf ();
	}
}

void CWriteOut () {
	cout << _A << " " << _B << " " << _C;	
}

int main () {
	ParseIn ();
	Core ();
	CWriteOut ();
	
	return 0;	
}
