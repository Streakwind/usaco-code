#define ll long long 

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Customer {
    ll _cookies;
    ll _muffins;
    ll _maxWait;
};

int _testCases = 0;
int _maxi = 0;
ll _cookieTime = 0;
ll _muffinTime = 0;

vector<Customer> _friends;

//given inequalities, solve for lower and upper bounds of the new time for cookies (NOT dependent on muffins)
bool isValid (int n) {
    ll lowCookie = max((ll)1, _cookieTime - n);
    ll highCookie = min(_cookieTime + _muffinTime - n - 1, _cookieTime);

    ll bigThing = 0; //t_c + t_m - n in the inequality -> total time

    bigThing = _cookieTime + _muffinTime - n;

    for (int i = 0; i < _friends.size(); i++) {
        int cookies = _friends[i]._cookies;
        int muffins = _friends[i]._muffins;

        if (cookies > muffins) { //more cookies -> upper bound
            highCookie = min(highCookie, (_friends[i]._maxWait - bigThing * muffins) / (cookies - muffins));
        } else if (cookies < muffins) { //less cookies -> lower bound
            if ((_friends[i]._maxWait - bigThing * muffins) % (cookies - muffins) == 0) {
                lowCookie = max(lowCookie, (_friends[i]._maxWait - bigThing * muffins) / (cookies - muffins));
            } else { //round up
                lowCookie = max(lowCookie, (_friends[i]._maxWait - bigThing * muffins) / (cookies - muffins) + 1);
            }
        } else { //cookies = muffins, but divison by 0 is not allowed
            //given the inequality: (ai - bi)x <= ci - bi*d, and ai-bi = 0, we can solve that bi*d <= ci 
            //!bi*d <= ci => bi*d > ci
            if (cookies * bigThing > _friends[i]._maxWait) {
                return false;
            }
        }
    }

    return (lowCookie < highCookie+1);
}

void CoreCWriteOut () {
    ll l, m, r;
    ll res = 0;

    l = 0;
    r = _cookieTime + _muffinTime;

    while (l < r+1) {
        m = l + (r-l)/2;

        if (isValid(m)) {
            r = m-1;

            res = m;
        } else {
            l = m+1;
        }
    }

    cout << res << endl;
}

int main () {  
    Customer solo;

    // ifstream inFile ("bakery.in");

    // inFile >> _testCases;

    cin >> _testCases;

    for (int i = 0; i < _testCases; i++) {
        // inFile >> _maxi >> _cookieTime >> _muffinTime;
        cin >> _maxi >> _cookieTime >> _muffinTime;
        
        for (int m = 0; m < _maxi; m++) {
            // inFile >> solo._cookies >> solo._muffins >> solo._maxWait;
            cin >> solo._cookies >> solo._muffins >> solo._maxWait;

            _friends.push_back(solo);
        }

        CoreCWriteOut ();

        _friends.clear();
    }

    // inFile.close();

    return 0;
}
