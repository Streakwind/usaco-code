

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> _grid;
vector<vector<bool>> _visited(1001, vector<bool>(1000, false));
int _gridSize = 0;
int _curArea = 0;
int _maxArea = 0;
int _curPerim = 0;
int _maxPerim = -1;

void ParseIn () {
    ifstream inFile ("perimeter.in");

    vector<char> curList;

    inFile >> _gridSize;

    for (int i = 0; i < _gridSize; i++) {
        char a;
        for (int m = 0; m < _gridSize; m++) {
            inFile >> a;

            curList.push_back(a);
        }

        _grid.push_back(curList);
        curList.clear();
    }
}

void floodfill(int r, int c, char type) {
	if ((r < 0 || r >= _gridSize || c < 0 || c >= _gridSize)
	    || _grid[r][c] != type                         
	    || _visited[r][c]                                 
	)
		return;

	_visited[r][c] = true;
    _curArea++;

    //add to perimeter

    int avail = 4;

    if (r != 0 && _grid[r-1][c] == '#') {avail--;}
    if (r != _gridSize - 1 && _grid[r+1][c] == '#') {avail--;}
    if (c != 0 && _grid[r][c-1] == '#') {avail--;}
    if (c != _gridSize - 1 && _grid[r][c+1] == '#') {avail--;}

    //cout << avail << endl;

    _curPerim += avail;

	floodfill(r, c + 1, type);
	floodfill(r, c - 1, type);
	floodfill(r - 1, c, type);
	floodfill(r + 1, c, type);
}

void Core () {

    for (int i = 0; i < _gridSize; i++) {

        for (int m = 0; m < _gridSize; m++) {
            //cout << endl;
            
            if (!_visited[i][m]) {
                _curArea = 0;
                _curPerim = 0;
                floodfill(i, m, '#');

                if (_maxArea == _curArea) {
                    if (_maxPerim != -1) {_maxPerim = min(_maxPerim, _curPerim);}
                    else {_maxPerim = _curPerim;}
                }
                else {_maxPerim = max(_maxPerim, _curPerim);}

                _maxArea = max(_maxArea, _curArea);
            }
        }
    }
}

void CWriteOut () {
    ofstream outFile ("perimeter.out");

    outFile << _maxArea << " " << _maxPerim << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
