

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Cell {
    int _x;
    int _y;
};

vector<Cell> _cowList;
int _cowGrid[1009][1009];
int _maxi = 0;

void DisplayGrid() {
    for (int i = 0; i < 4; i++) {
        for (int m = 0; m < 4; m++) {
            cout << _cowGrid[i][m] << " ";
        }

        cout << endl;
    }
}
void ParseIn () {
    Cell solo;
    ifstream inFile ("comfyCow.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> solo._x >> solo._y;

        _cowList.push_back(solo);
    }
}

void CParseIn () {
    Cell solo;

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        cin >> solo._x >> solo._y;

        _cowList.push_back(solo);
    }
}

//modify res by checking adj cow numbers
int CalcAdjacent (Cell oriCow, Cell cowPos, int curRes) {
    if (cowPos._x < 0) {
        return curRes;
    }

    if (cowPos._y < 0) {
        return curRes;
    }

    if (_cowGrid[cowPos._y][cowPos._x] > 0) {
        _cowGrid[cowPos._y][cowPos._x]++;
        _cowGrid[oriCow._y][oriCow._x]++;

        if (_cowGrid[cowPos._y][cowPos._x] == 4 || _cowGrid[oriCow._y][oriCow._x] == 4) {
            curRes++;
        }

        if (_cowGrid[cowPos._y][cowPos._x] > 4 || _cowGrid[oriCow._y][oriCow._x] > 4) {
            curRes--;
        }
    }

    return curRes;
}

void InitializeCowGrid () {
    //initialize arr _cowGrid
    for (int i = 0; i < 1009; i++) {
        for (int m = 0; m < 1009; m++) {
            _cowGrid[i][m] = 0;
        }
    }
}

void Core () {
    Cell solo;
    Cell curCell;
    int res = 0;

    InitializeCowGrid();

    for (int i = 0; i < _cowList.size(); i++) {
        solo = _cowList[i];
        _cowGrid[solo._y][solo._x] = 1;

        //cout << "(" << solo._x << ", " << solo._y << ")" << endl;

        //x-1
        curCell = solo;
        curCell._x -= 1;
        //cout << "(" << curCell._x << ", " << curCell._y << ")" << endl;
        res = CalcAdjacent(solo, curCell, res);
        
        
        //y-1
        curCell = solo;
        curCell._y -= 1;
        //cout << "(" << curCell._x << ", " << curCell._y << ")" << endl;
        res = CalcAdjacent(solo, curCell, res);

        //x+1
        curCell = solo;
        curCell._x += 1;
        //cout << "(" << curCell._x << ", " << curCell._y << ")" << endl;
        res = CalcAdjacent(solo, curCell, res);

        //y+1
        curCell = solo;
        curCell._y += 1;
        //cout << "(" << curCell._x << ", " << curCell._y << ")" << endl;
        res = CalcAdjacent(solo, curCell, res);

        //DisplayGrid();

        cout << res << endl;
    }
}

int main () {
    CParseIn ();
    Core ();

    return 0;
}
