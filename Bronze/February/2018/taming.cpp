

#include <iostream>
#include <fstream>

using namespace std;

int _dayArr[109]{}; //1-> cows ran away, 2-> unknown -1-> cows did not runaway
int _min = 0;
int _nonCounter = 0; //days where _dayArr[i] = 2
int _maxi = 0;
bool valid = true;

void DisplayDayArr (int maxi) {
  for (int i = 1; i < maxi; i++) {
   cout << _dayArr[i] << " "; 
  }

  cout << endl;
}

//what: true->already modified, false->not modified
bool IsModified (int day) {
  if (_dayArr[day] == 0) {return false;}

  return true;
}

void ParseIn () {
  int curInt = 0;

  ifstream inFile ("taming.in");

  inFile >> _maxi;

  for (int i = 1; i < _maxi+1; i++) { //start at one because day one
    inFile >> curInt;

    if (i == 1) {
      if (curInt != 0 && curInt != -1) {valid = false; break;}
      _dayArr[i] = 1;
      //DisplayDayArr(_maxi);
      continue;
    } //given cows run away on day one
    
    if (curInt == -1) {_dayArr[i] = 2;}
    if (curInt != -1) {
      if (IsModified(i) && _dayArr[i] != 1) {valid = false; break;}
      _dayArr[i-curInt] = 1;

      for (int m = i; m > i-curInt; m--) {
        if (_dayArr[m] == 2 || _dayArr[m] == 0 || _dayArr[m] == -1) {_dayArr[m] = -1;}
        else {valid = false; break;}
      }
      if (curInt != 0) {_dayArr[i] = -1;}
    }

    //DisplayDayArr(_maxi);
  }
  
  inFile.close();
}

void Core () {
  for (int i = 1; i < _maxi+1; i++) {
    //cout << _dayArr[i] << " ";
    
    if (_dayArr[i] == 1) {_min++;}
    if (_dayArr[i] == 2) {_nonCounter++;}
  }
}

void WriteOut () {
  ofstream outFile ("taming.out");

  if (valid) {outFile << _min << " " << _min+_nonCounter << endl;}
  if (!valid) {outFile << -1 << endl;}

  outFile.close();
}

int main () {
  ParseIn ();
  Core ();
  WriteOut ();

  return 0;
}