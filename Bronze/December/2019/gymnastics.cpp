

#include <iostream>
#include <fstream>

using namespace std;

int _res = 0;
int _ranks[19][29];
int _rows = 0;
int _columns = 0;

void ParseIn () {
    int curInt = 0;

    ifstream inFile ("gymnastics.in");

    inFile >> _rows >> _columns;

    for (int i = 0; i < _rows; i++) {
        for (int m = 0; m < _columns; m++) {
            inFile >> curInt; //curInt is cow, i is row, m is rank

            _ranks[i][curInt-1] = m;
        }
    }

    inFile.close();
}

void Core () {
    for (int i = 0; i < _columns; i++) {
        for (int m = i+1; m < _columns; m++) {
            //two cows found
            bool better = false;
            bool worse = false;

            for (int j = 0; j < _rows; j++) {
                if (_ranks[j][i] < _ranks[j][m]) {better = true;}
                if (_ranks[j][i] > _ranks[j][m]) {worse = true;}
            }

            if (better ^ worse) {_res++;}
        }
    }
}

void WriteOut () {
    ofstream outFile ("gymnastics.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
