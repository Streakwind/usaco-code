

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<bool>> _waypCoord(501, vector<bool>(501, false));
vector<vector<int>> _grid;
vector<vector<bool>> _visited(501, vector<bool>(501, false));
int _waypAmt = 0;
int _width = 0; // N
int _height = 0; // M
int _lowest = 0;
pair<int, int> startCoord;

void ParseIn () {
    vector<int> curList;

    ifstream inFile ("ccski.in");

    inFile >> _height >> _width;

    for (int i = 0; i < _height; i++) {
        int cur = 0;

        for (int m = 0; m < _width; m++) {
            inFile >> cur;
            
            curList.push_back(cur);
        }
        
        _grid.push_back(curList);
        curList.clear();
    }

    for (int i = 0; i < _height; i++) {
        int cur = 0;

        for (int m = 0; m < _width; m++) {
            inFile >> cur;

            //waypoint found
            if (cur == 1) {
                _waypCoord[i][m] = true;
                _waypAmt++;

                startCoord.first = i;
                startCoord.second = m;
            }
        }
    }

    inFile.close();
}

int abs (int a) {
    if (a < 0) return a * -1;
    return a;
}

void floodfill(int r, int c, int d) {
	if ((r < 0 || r >= _height || c < 0 || c >= _width)                      
	    || _visited[r][c]                               
	)
		return;

    //cout << r << "," << c << endl;
	_visited[r][c] = true;

    //find the four squares around it
    //cout << _grid[r][c] -_grid[r][c-1] << endl;

    if (r > 0) {
        if (abs(_grid[r][c] -_grid[r-1][c]) > d) {}
        else {floodfill(r - 1, c, d);}
    }
    if (c > 0) {
        if (abs(_grid[r][c] -_grid[r][c-1]) > d) {}
        else {floodfill(r, c - 1, d);}
    }
    if (r < _height-1) {
        if (abs(_grid[r][c] -_grid[r+1][c]) > d) {}
        else {floodfill(r + 1, c, d);}
    }
    if (c < _width-1) {
        if (abs(_grid[r][c] -_grid[r][c+1]) > d) {}
        else {floodfill(r, c + 1, d);}
    }
}

bool isValid (int elev) {
    int found = 0;

    _visited = vector<vector<bool>>(501, vector<bool>(501, false));

    floodfill(startCoord.first, startCoord.second, elev);

    for (int i = 0; i < _height; i++) {
        for (int m = 0; m < _width; m++) {
            if (_visited[i][m] && _waypCoord[i][m]) {
                found++;

                //cout << "found at " << i << ", " << m << endl;
            }
        }
    }

    return (_waypAmt == found);
}

void Core () {
    int l, m, r;
    l = 0;
    r = 1000000002;

    // cout << isValid(27) << endl;

    while (l < r + 1) {
        m = l + (r-l) / 2;

        if (isValid(m)) {
            r = m-1;

            _lowest = m;
        } else {
            l = m+1;
        }
    }
}

void WriteOut () {
    ofstream outFile ("ccski.out");

    outFile << _lowest << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
