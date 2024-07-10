//submitted to https://www.spoj.com/problems/HAYBALE/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int _maxi = 0;
int _commands = 0;
int _stackArr[1000009] = {};

int main () {
    int start = 0, end = 0;
    int stackNum = 0;
    map<int, vector<int>> tagStack; //num corrsponds to vector. 0 means end and 1 means start

    cin >> _maxi >> _commands;

    for (int i = 1; i < _maxi+1; i++) {
        tagStack[i] = {0, 0};
    }

    for (int i = 0; i < _commands; i++) {
        cin >> start >> end;

        tagStack[start][1]++;
        tagStack[end][0]++;
    }

    vector<int> resList;

    for (int i = 1; i < _maxi+1; i++) {
        stackNum += tagStack[i][1];
        stackNum -= tagStack[i][0];

        resList.push_back(stackNum);
    }

    sort(resList.begin(), resList.end());

    cout << resList[_maxi/2 + 1] << endl;

    return 0;
}
