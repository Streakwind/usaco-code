

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<bool> _visited;
vector<pair<int, int>> _cowList;
vector<vector<bool>> _isConnected;
vector<int> _powerList;

int _cowNum;
int _visitedAmt;

int _res = 0;

int dfsForReached (int cow) {
    //cout << "reached " << cow << endl;

    //original cow counts
    int curRes = 1;

    _visited[cow] = true;

    for (int i = 0; i < _cowNum; i++) {
        if (!_visited[i] && _isConnected[cow][i]) {
            _visited[i] = true;

            //cout << "from " << cow << " to " << i << endl;

            curRes += dfsForReached(i);
        }
    }

    return curRes;
}

void ParseIn () {
    int x, y, power;

    ifstream inFile ("moocast.in");

    inFile >> _cowNum;

    _visited.resize(_cowNum);

    for (int i = 0; i < _cowNum; i++) {
        inFile >> x >> y >> power;

        _cowList.push_back(make_pair(x, y));
        _powerList.push_back(power);
    }

    inFile.close();
}

void Core () {
    _isConnected = vector<vector<bool>> (_cowNum, vector<bool>(_cowNum));

    for (int i = 0; i < _cowNum; i++) {
        for (int m = 0; m < _cowNum; m++) {
            //square of distance between two cows
            int dist = 0;

            dist = ((_cowList[i].first - _cowList[m].first) * (_cowList[i].first - _cowList[m].first) + 
                   (_cowList[i].second - _cowList[m].second) * (_cowList[i].second - _cowList[m].second));
            
            //cout << "cow " << i << " and cow " << m << " distance^2: " << dist << " power^2: " << _powerList[i] * _powerList[i] << endl;

            if (dist > _powerList[i] * _powerList[i]) {_isConnected[i][m] = false;}
            else {_isConnected[i][m] = true;}
        }
    }
    
    _visited.resize(_cowNum);

    for (int i = 0; i < _cowNum; i++) {
        fill(_visited.begin(), _visited.end(), false);

        _res = max(_res, dfsForReached(i));
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
