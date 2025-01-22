

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Score {
  int _got;
  int _total;
};

vector<Score> _scoreList;
vector<int> _resList;
int _res = 0;

void ParseIn() {
  Score solo;
  char curChar;

  ifstream inFile("calcScore.in");

  for (int i = 0; i < 3; i++) {
    inFile >> solo._got >> curChar >> solo._total;

    _scoreList.push_back(solo);
  }

  inFile.close();
}

void Core() {
  Score solo;
  int probTotal = 0;
  int testCase = 0;
  int tempoRes = 0;

  probTotal = 1000 / _scoreList.size();

  for (int i = 0; i < _scoreList.size(); i++){
    solo = _scoreList[i];

    testCase = probTotal / solo._total;

    tempoRes = solo._got * testCase;

    _res += tempoRes;
  }

  cout << _res << endl;

}

int main() {
  ParseIn();
  Core();

  return 0;
}
