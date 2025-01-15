

#include <bits/stdc++.h>

using namespace std;

int _cowNum = 0;
vector<vector<int>> _adjList;
vector<vector<bool>> _reachable;

void ParseIn () {
    vector<int> curList;
    _adjList.push_back(curList);

    cin >> _cowNum;

    for (int i = 0; i < _cowNum; i++) {
        int temp = 0;

        for (int m = 0; m < _cowNum; m++) {
            cin >> temp;

            curList.push_back(temp);
        }

        while (curList.back() != (i+1)) {
            curList.pop_back();
        }
    
        // for (int i = 0; i < curList.size(); i++) {cout << curList[i] << endl;}

        _adjList.push_back(curList);
        curList.clear();
    }
}

void dfs (int src, int cur) {
    if (_reachable[src][cur]) return;

    _reachable[src][cur] = true;

    //cout << src << "<-" << cur << endl;

    for (auto node : _adjList[cur]) {
        dfs(src, node);
    }
}

void Core () {
    _reachable = vector<vector<bool>>(_cowNum+1, (vector<bool>(_cowNum+1, false)));

    for (int i = 1; i < _cowNum + 1; i++) {    
        dfs(i, i);
    } 

    for (int i = 1; i < _cowNum+1; i++) {
        for (int gift : _adjList[i]) {
            /* the dfs above finds all the vertices a cow [i] can reach
             * this are the gifts that it can exchange for
             * essentially, using [gift][i] swaps this to see if this can go both ways
             * e.g.
             * 2->1, 3, 2
             * 3->1, 2, 3
             * through the previous dfs, the following pairs of vertices return true:
             * [2][1], [2][3], [2][2], [3][1], [3][2], [3][3], but the following will be false:
             * [1][2], [1][3]
             * when traversing through the list of cow 2, you find that one of the gifts wanted is 1
             * unfortunately, 1 cannot go to 2 due to how the adjList of cow 1 is only [1], so [1]'s only connection is [1]
             * however, 3 can go to 2 so 2 takes it, prints the answer, and breaks
             * how does this assure no two cows get the same gift?
             * the cows are greedy, and will only choose a better gift
             * if 2s preference was [1, 2, 3, 4], then there would not be a route to 3 because 2 starts with 2 which is its 2nd best
             * any cows below its start will not be considered
             */

            if (_reachable[gift][i]) {
                cout << gift << endl;
                break;
            }
        }
    }
}

int main () {
    ParseIn ();
    Core ();

    return 0;    
}
