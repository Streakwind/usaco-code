#define ll long long

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ll _grassPatch = 0;
ll _nhojCows = 0;
ll _johnCows = 0;

vector<pair<ll, ll>> _grassPatchList; //.first = pos, .second = tastiness where -1 means its a nhoj cow
vector<ll> _resList;

void ParseIn () {
    ll curNum = 0;
    ll curTaste = 0;

    cin >> _grassPatch >> _nhojCows >> _johnCows;

    for (int i = 0; i < _grassPatch; i++) {
        cin >> curNum >> curTaste;

        _grassPatchList.push_back(make_pair(curNum, curTaste));
    }

    for (int i = 0; i < _nhojCows; i++) {
        cin >> curNum;

        _grassPatchList.push_back(make_pair(curNum, -1));
    }
}

void Core () {
    ll lastNhoj = -1;
    ll curSum = 0;

    sort(_grassPatchList.begin(), _grassPatchList.end());

    for (int i = 0; i < _grassPatchList.size(); i++) {
        if (_grassPatchList[i].second == -1) {
            if (lastNhoj == -1) {
                _resList.push_back(curSum);
            } else {
                ll curAns = 0;
                ll bestAns = 0;

                for (int m = lastNhoj+1, j = lastNhoj; m < i; m++) {
                    while (j + 1 < i && 
                           (_grassPatchList[j+1].first - _grassPatchList[m].first) * 2 < _grassPatchList[i].first - _grassPatchList[lastNhoj].first) {
                        curAns += _grassPatchList[++j].second;
                    }

                    bestAns = max(curAns, bestAns);

                    curAns -= _grassPatchList[m].second; // no longer included value
                }

                _resList.push_back(bestAns);

                _resList.push_back(curSum - bestAns);
            }

            lastNhoj = i;
            curSum = 0;
        } else {
            curSum += _grassPatchList[i].second;
        }
    }

    _resList.push_back(curSum); //rightmost
}

bool CompDown (ll a, ll b) {
    return a > b;
}

void CWriteOut () {
    ll res = 0;

    sort(_resList.begin(), _resList.end(), CompDown);

    for (int i = 0; i < _johnCows; i++) {
        res += _resList[i];
    }

    cout << res << endl;
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
