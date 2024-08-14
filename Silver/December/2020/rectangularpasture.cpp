#define ll long long

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int _maxi = 0;
ll _res = 0;
vector<pair<int, int>> _cordList;
vector <vector<int>> _prefSum;

void CParseIn () {
    int x = 0, y = 0;
    
    vector<int> curList;

    cin >> _maxi; 

    for (int i = 0; i < _maxi; i++) {
        cin >> x >> y;

        _cordList.push_back(make_pair(x, y));
    }

    //max is 2500, add 1 row/column so 2500 + 2 = 2502
    for (int i = 0; i < 2502; i++) {
        for (int m = 0; m < 2502; m++) {
            curList.push_back(0);
        }

        _prefSum.push_back(curList);
        curList.clear();
    } 
}

ll rectSum (int startX, int startY, int endX, int endY) {
    return _prefSum[endX+1][endY+1] - _prefSum[startX][endY+1] - _prefSum[endX+1][startY] + _prefSum[startX][startY];
}

bool CompXCord (pair<int, int> a, pair<int, int> b) {return a.first < b.first;}
bool CompYCord (pair<int, int> a, pair<int, int> b) {return a.second < b.second;}

void Core () {
    int startX = 0, endX = 0;
    ll curRes = 0;

    _res++; //acount for empty subset

    //new values to cordList
    sort(_cordList.begin(), _cordList.end(), CompXCord);
    for (int i = 0; i < _maxi; i++) {_cordList[i].first = i+1;}

    sort(_cordList.begin(), _cordList.end(), CompYCord);
    for (int i = 0; i < _maxi; i++) {_cordList[i].second = i+1;}

    //add new cords into grid
    for (int i = 0; i < _maxi; i++) {_prefSum[_cordList[i].first][_cordList[i].second] = 1;}

    //calculate prefSum for cords
    for (int i = 1; i < _maxi+1; i++) {
        for (int m = 1; m < _maxi+1; m++) {_prefSum[i][m] += _prefSum[i-1][m] + _prefSum[i][m-1] - _prefSum[i-1][m-1];} //must be += because you need to add the existing value
    }

    //find answer -> points inside a rectangle
    for (int i = 0; i < _maxi; i++) {
        for (int m = i; m < _maxi; m++) {
            //subtract 1 because 1 will be added in sum
            startX = min(_cordList[i].first, _cordList[m].first) - 1;
            endX = max(_cordList[i].first, _cordList[m].first) - 1;
                    
            // if(startX < 0) {startX = 0;} 
            // if (endX < 0) {endX = 0;}

            curRes = rectSum(0, i, startX, m) * rectSum(endX, i, _maxi-1, m);

//            cout << rectSum(0, i, startX, m) << ", " << rectSum(endX, i, _maxi-1, m) << endl;

            _res += curRes;
        }
    }
}

void CWriteOut () {
    cout << _res << endl;
}

int main () {
    CParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
