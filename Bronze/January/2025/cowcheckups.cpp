

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _numCows = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll res = 0;
    ll start = 0;
    //parse data
    cin >> _numCows;
    
    vector<int> resList(_numCows+1, 0);
    vector<int> ori(_numCows, 0);
    vector<int> compareTo(_numCows, 0);

    for (int i = 0; i < _numCows; i++) cin >> ori[i];
    for (int i = 0; i < _numCows; i++) cin >> compareTo[i];

    //determine all of the elements that are already in the correct position
    for (int i = 0; i < _numCows; i++) start += (ori[i] == compareTo[i]);

    //iterate through all possible (l, r) pairs from a given start position
    auto expand = [&](int l, int r) {
        ll cur = start;

        for (; l > -1 && r < _numCows; l--, r++) {
            // make sure to substract the equal ones from cur as they are no longer in the correct position
            cur += ((ori[l] == compareTo[r]) + (ori[r] == compareTo[l])) - ((ori[l] == compareTo[l]) + (ori[r] == compareTo[r]));
            resList[cur]++;
        }
    };

    //iterate through all possible (l, r) starting positions
    for (int i = 0; i < _numCows; i++) {
        expand(i, i);
        expand(i, i+1);
    }

    for (int i : resList) cout << i << endl;    

    return 0;

}
