#define ml myList
#define ll long long

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<ll> Final (ll maxi, vector<ll> myList) {
    vector<ll> resList;

    for (ll i = 0; i < maxi-1; i++) {
        //cout << ml[i] << ml[i+1] << ml[i+2] << endl;

        if (ml[i] == ml[i+1] || ml[i] == ml[i+2]) {resList.push_back(ml[i]);}
        if (ml[i+1] == ml[i+2]) {resList.push_back(ml[i+1]);}
    }

    if (resList.size() == 0) {resList.push_back(-1);}

    return resList;
}

int main () {
    ll maxCases = 0;
    ll maxi = 0;
    ll curll = 0;
    vector<ll> myList;
    vector<ll> resList;
    map<ll, ll> seenRes;

    cin >> maxCases;

    for (ll i = 0; i < maxCases; i++) {
        cin >> maxi;
        for (ll m = 0; m < maxi; m++) {
            cin >> curll;

            myList.push_back(curll);
        }

        resList = Final(maxi, myList);

        sort(resList.begin(), resList.end());

        for (ll m = 0; m < resList.size(); m++) {
            if(seenRes.count(resList[m])) {continue;}

            if (m != 0) {
                cout << " ";
            }   

            cout << resList[m];
            seenRes[resList[m]] = 1;
        }

        cout << endl;

        myList.clear();
        seenRes.clear();
    }

    return 0;
}
