//n^3 solution below. solved 8/10. after this is the n^2 solution that gets 10/10

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <set>
// #include <map>

// using namespace std;

// vector <vector<int>> _grid;
// map<int, int> _existingColors;
// set<int> _notFirst;

// int _maxi = 0;
// int _colors = 0;

// int _res = 0;

// void ParseIn () {
//     int curNum = 0;
//     vector<int> curList;

//     ifstream inFile ("art.in");

//     inFile >> _maxi; 

//     for (int i = 0; i < _maxi; i++) {
//         for (int m = 0; m < _maxi; m++) {
//             inFile >> curNum;

//             _existingColors[curNum]++;

//             curList.push_back(curNum);
//         }

//         _grid.push_back(curList);
//         curList.clear();
//     }

//     _colors = _maxi * _maxi;

//     inFile.close();

// }

// //eliminate possibility of color if its on top of another
// void OnTop (int color) {
//     int top = 0, bottom = INT32_MAX, left = INT32_MAX, right = 0;
    
//     //find top, bottom, left, and right
//     for (int i = 0; i < _maxi; i++) {
//         for (int m = 0; m < _maxi; m++) {
//             if (_grid[i][m] == color) {
//                 top = max(top, i);
//                 bottom = min(bottom, i);

//                 right = max(right, m);
//                 left = min(left, m);
//             }
//         }
//     }

//     for (int i = bottom; i < top+1; i++) {
//         for (int m = left; m < right+1; m++) {
//             if (_grid[i][m] != color && _grid[i][m] != 0) {
//                 cout << "Color " << _grid[i][m] << " is on top of color " << color << endl; 

//                 _notFirst.insert(_grid[i][m]);
//             }
//         }
//     }
// }

// void Core () {
//     //NOTE: _existingColors includes 0!

//     if (_existingColors.size() > 2) {
//         for (auto i : _existingColors) {if (i.first != 0) {OnTop(i.first);}}

//         _res = _colors;

//         _res -= (int)_notFirst.size();
//     } 

//     if (_existingColors.size() < 3) {_res = _colors - _existingColors.size(); _res++;}
// }

// void WriteOut () {
//     ofstream outFile ("art.out");

//     outFile << _res << endl;

//     outFile.close();
// }

// int main () {
//     ParseIn ();
//     Core ();
//     WriteOut ();

//     return 0;
// }
//usaco.guide strat because my n^3 solution didn't work :`)

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

//define rectangles min and max coords
struct Rectangle {
    int _minY;
    int _maxY;
    int _minX;
    int _maxX;
};

vector <vector<int>> _grid;
map<int, Rectangle> _existingColors;
set<int> _notFirst;

int _maxi = 0;
int _colors = 0;

int _res = 0;

void ParseIn () {
    int curNum = 0;
    vector<int> curList;

    ifstream inFile ("art.in");

    inFile >> _maxi; 

    for (int i = 0; i < _maxi; i++) {
        for (int m = 0; m < _maxi; m++) {
            inFile >> curNum;

            if (_existingColors.find(curNum) == _existingColors.end()) {_existingColors[curNum] = {i, i, m, m};}

            _existingColors[curNum]._minX = min(_existingColors[curNum]._minX, m);
            _existingColors[curNum]._maxX = max(_existingColors[curNum]._maxX, m);
            _existingColors[curNum]._minY = min(_existingColors[curNum]._minY, i);
            _existingColors[curNum]._maxY = max(_existingColors[curNum]._maxY, i);

            curList.push_back(curNum);
        }

        _grid.push_back(curList);
        curList.clear();
    }

    _colors = _maxi * _maxi;

    inFile.close();

    _existingColors.erase(0);
}

void Core () {
    set<int> validColors; //no duplicates because set
    vector< vector<int>> rectangleGrid (_maxi+1, vector<int> (_maxi+1));

    _res = _colors - _existingColors.size();

    if (_existingColors.size() > 1) {
        for (auto i : _existingColors) {
            cout << "(" << i.second._minX << ", " << i.second._minY << ") (" << i.second._maxX << ", " << i.second._maxY << ")" << endl;
            validColors.insert(i.first);

            rectangleGrid[i.second._minY][i.second._minX]++;
            rectangleGrid[i.second._maxY+1][i.second._maxX+1]++;
            rectangleGrid[i.second._maxY+1][i.second._minX]--;
            rectangleGrid[i.second._minY][i.second._maxX+1]--;
        }

        for (int i = 0; i < _maxi; i++) {
            for (int m = 0; m < _maxi; m++) {
                cout << rectangleGrid[i][m] << " ";
            }

            cout << endl;
        }

        for (int i = 0; i < _maxi; i++) {
            for (int m = 0; m < _maxi; m++) {
                //prefix sum stuff
                if (i > 0) {rectangleGrid[i][m] += rectangleGrid[i-1][m];}
                if (m > 0) {rectangleGrid[i][m] += rectangleGrid[i][m-1];}
                if (i > 0 && m > 0) {rectangleGrid[i][m] -= rectangleGrid[i-1][m-1];}

                //cout << rectangleGrid[i][m] << " ";

                if (rectangleGrid[i][m] > 1) {validColors.erase(_grid[i][m]);}
            }

            //cout << endl;
        }

        _res += validColors.size();
    }
}

void WriteOut () {
    ofstream outFile ("art.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
