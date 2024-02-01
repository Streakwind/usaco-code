#define ll long long

#include <iostream>
#include <vector>

using namespace std;

ll absA (ll a) {
    if (a < 0) {return a * -1;}

    return a;
}

ll factA (ll a) {
    ll res = 1;

    for (int i = a; i > 0; i--) {
        res *= i;
    }

    return res;
}
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    ll maxi = 0;
    ll curInt = 0;
    ll res = 0;
    ll modifier = 0;
    // ll maxMod = 1;
    ll needed = 0;
    // ll curFact = 0;
    ll cc = 2;
    vector<ll> myList;

    cin >> maxi;

    for (ll i = 0; i < maxi; i++) {
        cin >> curInt;

        myList.push_back(curInt);
    }

    for (ll i = 0; i < maxi; i++) {
        // myList[i] += modifier;

        // cout << myList[i] << endl;

        if (myList[i] == 0) {continue;}

        needed = 0 - myList[i];
        
        // cout << needed << endl;
        // cout << i << "," << cc << endl;
        for (ll m = i+1; m < maxi; m++) {
            //cout << "prev->" << myList[m] << endl;
            myList[m] += needed*cc;

            //cout << "new->" << myList[m] << endl;

            cc++;
        }

        cc = 2;

        res += absA(myList[i]);

        // modifier += cc*needed;

        // cout << modifier << endl;

        //cc++;
    } 

    cout << res << endl;

    return 0;
}
