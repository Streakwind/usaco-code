#define ll long long

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<ll, ll>> _grid;
ll _maxCow = 0;
// ll _lastPatch = 0;
ll _res = 0;

void ParseIn () {
    ll start = 0, end = 0;
    ll maxi = 0;

    ifstream inFile ("socdist.in");

    inFile >> _maxCow >> maxi;

    for (ll i = 0; i < maxi; i++) {
        inFile >> start >> end;

        _grid.push_back(make_pair(start, end)); 
    }

    // _lastPatch = end;

    inFile.close();

    sort(_grid.begin(), _grid.end());
}

bool isValid (ll n) {
    ll last = _grid[0].first;
    ll curInterval = 0;
    ll cows = 1;

    cout << endl;

    while (last + n < _grid[_grid.size()-1].second + 1) {
        //check if we need to go to the next interval
        while (_grid[curInterval].second < last + n) {
            curInterval++;
        }

        //cout << last << "->" << _grid[curInterval].first << ", " << _grid[curInterval].second << endl;
        
        //cow is placed at either n spaces after or the start of the next interval, depending on which is larger
        //if the start of the next interval is larger, that means that the last cow + n does not belong in an interval with grass
        last = max(_grid[curInterval].first, last + n);
        
        cows++;

        if (cows == _maxCow) {return true;}
    }
    
    return (cows >= _maxCow);
} 

void Core () {
    ll l, m, r;

    l = 0;
    r = _grid[_grid.size()-1].second;

    while (l < r+1) {
        m = l + (r-l)/2;

        if (isValid(m)) {
            l = m+1;

            _res = m;
        } else {
            r = m-1;
        }
    }
}

void WriteOut () {
    ofstream outFile ("socdist.out");
    
    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
