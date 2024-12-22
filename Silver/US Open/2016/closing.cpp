

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXI = 3009;

vector<vector<int>> _adjList(MAXI);
vector<bool> _visited(MAXI);
vector<bool> _closed(MAXI);
vector<bool> _resList;
vector<int> _changeList;

int _numPaths = 0;
int _numChanges = 0;
int _visitedAmt;

void ParseIn () {
    int start, end;

    ifstream inFile ("closing.in");

    inFile >> _numChanges >> _numPaths;

    _changeList.resize(_numChanges);

    for (int i = 0; i < _numPaths; i++) {
        inFile >> start >> end;

        _adjList[start].push_back(end);
        _adjList[end].push_back(start);
    }

    for (int i = 0; i < _numChanges; i++) {
        inFile >> _changeList[i];
    }

    inFile.close();
}

void dfs (int s) {
    if (_visited[s] || _closed[s]) return;

    _visited[s] = true;

    _visitedAmt++;

    // cout << s << endl;

    for (int node : _adjList[s]) {
        if (!_visited[node]) {dfs(node);}
    }
}

void Core () {
    int lastBarn = _changeList[_changeList.size() - 1];

    fill(_closed.begin(), _closed.end(), false);

    dfs(1);

    // cout << endl;

    if (_visitedAmt == _numChanges) {
        _resList.push_back(true);
    } else {
        _resList.push_back(false);
    }

    for (int i = 0; i < _numChanges-1; i++) {
        _visitedAmt = 0;
        fill(_visited.begin(), _visited.end(), false);

        _closed[_changeList[i]] = true;

        dfs(lastBarn);

        //i-1 because the first change is at index 0
        if (_visitedAmt == _numChanges - i - 1) {
            _resList.push_back(true);
        } else {
            _resList.push_back(false);
        }
    }
}

void CWriteOut () {
    ofstream outFile ("closing.out");

    for (int i = 0; i < _resList.size(); i++) {
        if (_resList[i]) {outFile << "YES" << endl;}
        else {outFile << "NO" << endl;}
    }

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
