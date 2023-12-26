//oops spelled it wrong - its aircownditioning not aircowditioning

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct AirC {
    int _start;
    int _end;
    int _temp;
    int _cost;
};

const int COWNUM = 109;
int _cows = 0;
int _conditioners = 0;
vector<AirC> _airCList;
int _cowArr[COWNUM]{};
int _minCost = INT32_MAX;

void CParseIn () {
    int start = 0;
    int end = 0;
    int temp = 0;
    AirC solo;

    cin >> _cows >> _conditioners;

    for (int i = 0; i < _cows; i++) {
        cin >> start >> end >> temp;

        for (int m = start; m < end+1; m++) {
            _cowArr[m] = temp;

            //cout << _cowArr[m];
        }
    }

    for (int i = 0; i < _conditioners; i++) {
        cin >> solo._start >> solo._end >> solo._temp >> solo._cost;

        _airCList.push_back(solo);

        //cout << _airCList[i]._start << _airCList[i]._end << _airCList[i]._temp << _airCList[i]._cost << endl;
    }
}

string GenerateBin (int num, int max) {
    string res = "";
    int remainder = 0;
    char remainderChar = '&';

    while (num > 0) {
        remainder = num % 2;
        remainderChar = remainder + '0';

        res += remainderChar;
        
        num /= 2;
    }

    int neededRange = 0;

    neededRange = max - res.length();

    for (int i = 0; i < neededRange; i++) {
        res += '0';
    }

    reverse(res.begin(), res.end());

    return res;
}

int Power (int base, int exponent) {
    int res = 1;

    for (int i = 0; i < exponent; i++) {
        res *= base;
    }

    return res;
}

int MaxNum (int max) { //where max is amount of conditioners
    int res = 0;

    for (int i = 0; i < max; i++) {
        res += Power(2, i);
    }

    return res;
}

void Core () {
    int maxi = 0;
    string conditioners = "";
    int curCost = 0;
    int _cowBackup[COWNUM]{};

    maxi = MaxNum (_conditioners);

    copy(_cowArr, _cowArr+COWNUM, _cowBackup);

    // for (int i = 0; i < COWNUM; i++) {
    //     cout << _cowArr[i];
    // }
    
    // cout << endl;

    //cout << _cowArr[9] << endl;

    for (int i = 1; i < maxi+1; i++) {
        conditioners = GenerateBin(i, _conditioners);

        //cout << conditioners << endl;

        for (int m = 0; m < conditioners.length(); m++) {
            if (conditioners[m] == '1') {
                //cout << _airCList[m]._start << ", " << _airCList[m]._end << endl;

                for (int k = _airCList[m]._start; k < _airCList[m]._end+1; k++) {
                    _cowArr[k] -= _airCList[m]._temp;

                    //cout << _cowArr[k];
                }

                curCost += _airCList[m]._cost;
            }
        }

        bool works = true;

        for (int m = 0; m < COWNUM; m++) {

            if (_cowArr[m] > 0) {
                //cout << _cowArr[m] << ", " << curCost << endl;

                works = false;
                break;
            }
        }

        //cout << endl;

        if (works) {_minCost = min(_minCost, curCost);}

        curCost = 0;
        copy(_cowBackup, _cowBackup+COWNUM, _cowArr);
    }   
}

void CWriteOut () {
    cout << _minCost << endl;
}

int main () {
    CParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
