#define ll long long

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

ll _res = 0;

vector<ll> _hayBales;

ll _maxHay = 0;

void ParseIn () {
    int n = 0;
    ll curInt = 0;

    ifstream inFile ("angry.in");

    inFile >> n;

    for (int i = 0; i < n; i++) {
        inFile >> curInt;

        //account for decimals (round to 1 decimal point so use *10)
        _hayBales.push_back(curInt*10);

        _maxHay = max(_maxHay, curInt*10);
    }

    inFile.close();

    sort(_hayBales.begin(), _hayBales.end());
}

bool isValidL (ll pos, ll power, ll i) {
    if (i < 1) {
        // i < 0 => the previous call of this function had it such that everything worked with the last 
        //supplied position and power
        // pos - power < _hayBales[0] => the last function call resulted in the first haybale (0 index), 
        //so check if the last index explodes with the supplied position and power
        return ((i < 0) || (pos - power < _hayBales[i]+1));
    }

    ll prevI = i;

    //check how many hay bales can be affected by the current position and power
    //index i only exists if i > -1
    while ((i > -1) && (pos - power < _hayBales[i]+1)) {i--;}

    //prevI == i assures that progress has been made
    //if progress has not been made, that means this supplied position and power did nothing -> does not work
    //if progress has been made, check the next haybale position and power
    // i+1 because the while loop breaks when i is below the working conditions, so i+1 returns the position of the
    //last working haybale position
    //do not change i itself, for i supplies the starting point of the next haybale position
    return (!(prevI == i) && (isValidL(_hayBales[i+1], power-10, i)));
}

//same structure as function above but it goes right instead
bool isValidR (ll pos, ll power, ll i) {
    // note how its _hayBales.size() - 2 and not -1
    //this is because _hayBales.size() is not a valid index (zero-indexed) and 
    //I didn't use the >= sign
    if (i > _hayBales.size() - 2) {
        return ((i > _hayBales.size()-1) || (pos + power > _hayBales[i]-1));
    }

    ll prevI = i;

    //index i only exists if i < _hayBales.size()
    while ((i < _hayBales.size()) && (pos + power > _hayBales[i]-1)) {i++;}

    return (!(prevI == i) && (isValidR(_hayBales[i-1], power-10, i)));
}

void Core () {
    ll l, power, r;
    ll lPos, pos, rPos;

    bool found = false;

    l = 0;
    r = _maxHay;

    while (l < r+1) {
        ll optPos = 0;

        power = l + (r-l) / 2;

        //integers only, ll cannot produce a fractional position     
        lPos = 0;
        rPos = _maxHay;

        //with the power given, find right most pos because that'll make it easier for it to go right all the way
        //binary search for logN instead of N
        while (lPos < rPos + 1) {
            pos = lPos + (rPos-lPos) / 2;

            //haybale position that is >= to the current position, then go left from there
            auto closest = lower_bound(_hayBales.begin(), _hayBales.end(), pos);

            //make sure no weird values are passed
            if (*closest > pos-1 && isValidL(pos, power, closest - _hayBales.begin())) {
                //cout << pos << endl;
                
                lPos = pos+1;

                optPos = pos;
            }
            else {
                rPos = pos-1;
            }
        }

        //first element on right greater than (or equal to) optPos, gives the starting point
        // if a haybale happens to be at optPos, it doens't really matter because
        //the power is the same anyway so if it go left but not right it doesn't matter
        auto closest = lower_bound(_hayBales.begin(), _hayBales.end(), optPos);

        //no check needed this time because its already been checked on line 107
        if (isValidR(optPos, power, closest - _hayBales.begin())) {
            //cout << "!" << endl;

            r = power-1;

            _res = power;
        } else {
            l = power+1;
        }

        found = false;
    }
}

void WriteOut () {
    ofstream outFile ("angry.out");

    outFile << setprecision(1) << fixed << (double)_res / 10 << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
