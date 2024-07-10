

#include <iostream>
#include <algorithm>

using namespace std;

int _cowGrid[1009][1009] = {{}, {}};
int _maxi = 0;
int _res = 0;

void CParseIn () {
    int curInt = 0;

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        for (int m = 0; m < _maxi; m++) {cin >> curInt; _cowGrid[i][m] = curInt;}
    }
}

void Core () {  
    int rowMax = 0;
    int evenMaxR = 0;
    int oddMaxR = 0;

    int columnMax = 0;
    int evenMaxC = 0;
    int oddMaxC = 0;


    for (int i = 0; i < _maxi; i++) {
        for (int m = 0; m < _maxi; m++) {
            if (m % 2 == 0) {evenMaxR += _cowGrid[i][m];}
            if (m % 2 != 0) {oddMaxR += _cowGrid[i][m];}

            if (m % 2 == 0) {evenMaxC += _cowGrid[m][i];}
            if (m % 2 != 0) {oddMaxC += _cowGrid[m][i];}
        }

        rowMax += max(evenMaxR, oddMaxR);
        columnMax += max(evenMaxC, oddMaxC);

        evenMaxR = 0, oddMaxR = 0;
        evenMaxC = 0, oddMaxC = 0;
    }

    _res = max(rowMax, columnMax);
}

void CWriteOut () {
    cout << _res << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    CParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
