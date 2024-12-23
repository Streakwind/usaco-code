

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
    int _x;
    int _y;
    vector<int> _adj;
    bool _visited;
};

//usaco is dumb and doesn't support INT_MAX
const int MAXI = 2147483647;

vector<Cow> _cowList;
vector<vector<int>> _networkList;
vector<int> _curNetwork;

int _res = MAXI;
int _cows = 0;
int _connections = 0;

void ParseIn () {
    int a, b;
    
    ifstream inFile ("fenceplan.in");

    inFile >> _cows >> _connections;

    _cowList.resize(_cows);

    for (int i = 0; i < _cows; i++) {
        inFile >> _cowList[i]._x >> _cowList[i]._y;

        _cowList[i]._visited = false;
    }

    for (int i = 0; i < _connections; i++) {
        inFile >> a >> b;

        //cowlist is zero indexed so -1
        _cowList[a-1]._adj.push_back(b-1);
        _cowList[b-1]._adj.push_back(a-1);
    }
}

void dfs (int s) {
    _cowList[s]._visited = true;

    _curNetwork.push_back(s);

    for (int node : _cowList[s]._adj) {
        if (!_cowList[node]._visited) {dfs(node);}
    }
}

void Core () {
    for (int i = 0; i < _cowList.size(); i++) {
        if (!_cowList[i]._visited) {
            _curNetwork.clear();

            dfs(i);
            _networkList.push_back(_curNetwork);  
        }
    }

    int minX, maxX;
    int minY, maxY;

    for (vector<int> curNet : _networkList) {
        //cout << endl;

        minX = MAXI; maxX = 0;
        minY = MAXI; maxY = 0;

        for (int cow : curNet) {
            //cout << cow << endl;
            //cout << _cowList[cow]._x << ", " << _cowList[cow]._y << endl;

            minX = min(minX, _cowList[cow]._x);
            maxX = max(maxX, _cowList[cow]._x);
            minY = min(minY, _cowList[cow]._y);
            maxY = max(maxY, _cowList[cow]._y);
        }

        //cout << minX << ", " << minY << " : " << maxX << ", " << maxY << endl;

        _res = min(_res, 2 * (maxX - minX) + 2 * (maxY - minY));
    }
}

void CWriteOut () {
    ofstream outFile ("fenceplan.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
