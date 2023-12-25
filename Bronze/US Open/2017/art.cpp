

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int _rectangleArr[9][19][19]{}; //D1-> num D2->graphY D3-> graphX
vector< vector<int>> _resPainting;
int _res = 0;
int _maxi = 0;

void ParseIn () {
    string curStr = "";
    vector<int> curList;

    ifstream inFile ("art.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curStr;

        for (int m = 0; m < _maxi; m++) {
            curList.push_back(curStr[m] - '0');
        }

        _resPainting.push_back(curList);
        curList.clear();
    }

    inFile.close();
}

// void GenerateMaxRectangle (int num, int maxX, int maxY, int minX, int minY) {
//     for (int i = minY; i < maxY; i++) {
//         for (int m = minX; m < maxX; m++) {
//             _rectangleArr[num][i][m] = num;

//             cout << num;
//         }

//         cout << endl;
//     }
// }

// //what: -1-> nothing on top, anything else-> color on top of it
// vector<int> CheckIntersection (int num) {
//     vector<int> resList;

//     for (int i = 0; i < _maxi; i++) {
//         for (int m = 0; m < _maxi; m++) {
//             //cout << _resPainting[i][m] << endl;

//             if (_rectangleArr[num][i][m] != _resPainting[i][m] && _resPainting[i][m] != 0 && _rectangleArr[num][i][m] != 0) {
//                 resList.push_back(_resPainting[i][m]);
//             }
//         }
//     }

//     if (resList.empty()) {
//         return {-1};
//     }

//     return resList;
// }

// void Core () {
//     map<int, bool> workMap; //true-> not intersecting anything, false-> intersecting something
//     vector<int> topList;
//     int maxX = 0;
//     int maxY = 0;
//     int minX = 0;
//     int minY = 0;

//     for (int i = 1; i < 10; i++) {
//         for (int m = 0; m < _maxi; m++) {
//             for (int j = 0; j < _maxi; j++) {
//                 if (_resPainting[m][j] == i) {
//                     cout << m << "," << j << endl;
//                     if (maxX < j) {maxX = j+1;}
//                     if (maxY < m) {maxY = m+1;}
//                     if (minX > j) {minX = j-1;}
//                     if (minY > m) {minY = m-1;}
//                 }
//             }

//         }

//         GenerateMaxRectangle(i, maxX, maxY, minX, minY);

//         maxX = 0;
//         maxY = 0;

//         workMap[i] = true;
//     }

//     for (int i = 1; i < 10; i++) {
//         topList = CheckIntersection(i);

//         if (topList[0] != -1) {
//             for (int m = 0; m < topList.size(); m++) {
//                 workMap[topList[m]] = false;
//             }
//         }
//     }

//     for (int i = 1; i < 10; i++) {
//         if (workMap.count(i) != 0 && workMap[i] == true) {_res++;}
//     }
// }

//what: true->exist, false->not exist
bool ColorExist (int num) {
    for (int i = 0; i < _maxi; i++) {
        for (int m = 0; m < _maxi; m++) {
            if (num == _resPainting[i][m]) {return true;}
        }
    }

    return false;
}

//what: true->c1 on top of c2, false->c1 not on top of c2
bool OnTop (int color1, int color2) {
    int top = 0, right = 0;
    int bottom = _maxi, left = _maxi;

    for (int i = 0; i < _maxi; i++) {
        for (int m = 0; m < _maxi; m++) {
            if (_resPainting[i][m] == color2) {
                top = max(top, i);
                bottom = min(bottom, i);

                left = min(left, m);
                right = max(right, m);
            }
        }
    }

    for (int i = bottom; i < top+1; i++) {
        for (int m = left; m < right+1; m++) {
            if (_resPainting[i][m] == color1) {return true;}
        }
    }

    return false;
}

void Core () {
    for (int i = 1; i < 10; i++) {
        if (ColorExist(i)) {
            bool possible = true;
            
            for (int m = 1; m < 10; m++) {
                if (i != m && OnTop(i, m)) {possible = false; break;}
            }

            if (possible) {_res++;}
        }
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
