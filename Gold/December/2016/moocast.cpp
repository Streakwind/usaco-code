#define ll long long

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

vector<bool> _visited;
vector<pair<ll, ll>> _cowList;
vector<vector<ll>> _distList;

ll _cowNum;
ll _visitedAmt = 0;

ll _res = 0;

void dfs (ll cow, ll pow) {
    if (_visited[cow]) return;

    //cout << cow << endl;

    _visitedAmt++;

    _visited[cow] = true;

    for (ll i = 0; i < _cowNum; i++) {
        if (!_visited[i] && pow >= _distList[cow][i]) {
            dfs(i, pow);
        }
    }
}

void ParseIn () {
    ll x, y;

    ifstream inFile ("moocast.in");

    inFile >> _cowNum;

    _visited.resize(_cowNum);

    for (ll i = 0; i < _cowNum; i++) {
        inFile >> x >> y;

        _cowList.push_back(make_pair(x, y));
    }

    inFile.close();
}

void Core () {
    ll r = 0;

    _distList = vector<vector<ll>> (_cowNum, vector<ll>(_cowNum));

    for (ll i = 0; i < _cowNum; i++) {
        for (ll m = 0; m < _cowNum; m++) {
            //square of distance between two cows
            ll dist = 0;

            dist = ((_cowList[i].first - _cowList[m].first) * (_cowList[i].first - _cowList[m].first) + 
                   (_cowList[i].second - _cowList[m].second) * (_cowList[i].second - _cowList[m].second));
            
            //cout << "cow " << i << " and cow " << m << " distance^2: " << dist << " power^2: " << _powerList[i] * _powerList[i] << endl;

            _distList[i][m] = dist;

            r = max(r, dist);

            //cout << r << endl;
        }
    }
    
    _visited.resize(_cowNum);

    ll l = 0;
    ll m;

    while (l < r+1) {
        fill(_visited.begin(), _visited.end(), false);
        _visitedAmt = 0;

        //m is the power^2
        m = l + (r-l)/2;

        dfs(1, m);

        if (_visitedAmt == _cowNum) {
            r = m-1;

            //power^2 = money = m
            _res = m;
        } else {
            l = m+1;
        }

        //cout << endl;
    }
}

void CWriteOut () {
    ofstream outFile ("moocast.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
