#define ll unsigned long long

#include <iostream>
#include <vector>

using namespace std;

struct Candy {
    ll _startP;
    ll _endP;
};

ll _cows = 0;
ll _candy = 0; //candy cane
vector<ll> _cowList;
vector<Candy> _candyList;

void CParseIn () {
    ll curHeight = 0;
    Candy solo;

    solo._startP = 0;

    cin >> _cows >> _candy;

    for (ll i = 0; i < _cows; i++) {
        cin >> curHeight;

        _cowList.push_back(curHeight);
    }

    for (ll i = 0; i < _candy; i++) {
        cin >> curHeight;

        solo._endP = curHeight;

        _candyList.push_back(solo);
    }
}

//what: true-> done false-> not done
// bool IsDone () {
//     cout << "hi" << endl;

//     for (ll i = 0; i < _cowList.size(); i++) {
//         for (ll m = 0; m < _candyList.size(); m++) {
//             cout << "cow height->" << _cowList[i] << ", candy min height->" << _candyList[m]._startP << endl;

//             if (_cowList[i] > _candyList[m]._startP && _candyList[m]._startP != _candyList[m]._endP) {
//                 cout << "yay" << endl;

//                 return false;
//             }
//         }
//     }

//     return true;
// }

void Core () {
    Candy newHeight;
    bool prev = true;
    ll resHeight = 0;

    for (ll i = 0; i < _candyList.size(); i++)  {

        for (ll m = 0; m < _cowList.size(); m++) {
            resHeight = _cowList[m];
            prev = false;

            //cout << "[" << _candyList[i]._startP << ", " << _candyList[i]._endP << "] with resHeight " << resHeight << " and original cow height " << _cowList[m] << endl;

            if (_candyList[i]._endP == _candyList[i]._startP) { //CRUCIAL saves lots of time, solves 11, 13, 14
                break;
            }

            //starting here, might be problems
            if (_candyList[i]._endP < resHeight+1) {
                newHeight._startP = _candyList[i]._endP;
                newHeight._endP = _candyList[i]._endP;

                resHeight += _candyList[i]._endP;
                resHeight -= _candyList[i]._startP;

                _candyList[i] = newHeight;

                prev = true;
            }

            if (_candyList[i]._startP < resHeight && !prev) {
                newHeight._startP = resHeight;
                newHeight._endP = _candyList[i]._endP;
                
                resHeight += _cowList[m];
                resHeight -= _candyList[i]._startP;

                _candyList[i] = newHeight;
            }

            _cowList[m] = resHeight;

            //cout << "[" << _candyList[i]._startP << ", " << _candyList[i]._endP << "] with resHeight " << resHeight << " and new cow height " << _cowList[m] << endl;
            //cout << endl;
        } 

        //cout << endl;
    }
}

void CWriteOut () {
    for (ll i = 0; i < _cowList.size(); i++) {
        cout << _cowList[i] << endl;
    }
}

int main () {
    CParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
