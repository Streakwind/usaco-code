#define ll long long

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXI = 1e5+9;
const int MAX_INT = 2147483647;

vector<vector<int>> _adjList;
vector<vector<int>> _connectedComponents;
vector<int> _componentNum;

int _numBarns = 0;
ll _res = 0;

void ParseIn () {
    int numPaths;
    int a, b;

    cin >> _numBarns >> numPaths;

    //cout << _numBarns << ", " << numPaths << endl;

    for (int i = 0; i < _numBarns; i++) {
        _connectedComponents[i].clear();
        _componentNum[i] = -1;
        _adjList[i].clear();
    }

    for (int i = 0; i < numPaths; i++) {
        cin >> a >> b;

        _adjList[--a].push_back(--b);
        _adjList[b].push_back(a);
    }
}

void dfs (int cur, int num) {
    if (_componentNum[cur] != -1) return;

    _componentNum[cur] = num;

    for (int node : _adjList[cur]) {
        dfs(node, num);
    }
}

ll cost (int fieldA, int fieldB) {
    ll dist = MAX_INT;

    for (int comp : _connectedComponents[fieldA]) {
        int i = lower_bound(_connectedComponents[fieldB].begin(), _connectedComponents[fieldB].end(), comp) - _connectedComponents[fieldB].begin();

        if (i > 0) {dist = min(dist, (ll)abs(_connectedComponents[fieldB][i - 1] - comp));}
        if (i < _connectedComponents[fieldB].size()) {dist = min(dist, (ll)abs(_connectedComponents[fieldB][i] - comp));}
    }

    return dist*dist;
}

void Core () {
    int connectedComp = -1;

    for (int i = 0; i < _numBarns; i++) {
        if (_componentNum[i] == -1) dfs(i, ++connectedComp);
    }

    for (int i = 0; i < _numBarns; i++) {
        _connectedComponents[_componentNum[i]].push_back(i);
    }

    //cout << cost(_componentNum[0], _componentNum[_numBarns-1]) << endl;

    _res = cost(_componentNum[0], _componentNum[_numBarns-1]);

    for (int i = 1; i < connectedComp; i++) {
        _res = min(_res, cost(i, _componentNum[0]) + cost(i, _componentNum[_numBarns-1]));
    }
}

void CWriteOut () {
    cout << _res << endl;
}

int main () {
    _connectedComponents.resize(MAXI);
    _componentNum.resize(MAXI);
    _adjList.resize(MAXI);

    int t = 0;

    //freopen("infile.in", "r", stdin);

    cin >> t;
    
    for (int i = 0; i < t; i++) {
        ParseIn ();
        Core ();
        CWriteOut ();
    }

    return 0;
}
