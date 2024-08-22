#define ll long long

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Boot {
    ll _depth;
    ll _range;
    ll _index;
};

vector<ll> _resList;
vector<ll> _snowList;
vector<Boot> _bootList;

ll _maxSnow = 0;
ll _maxBoot = 0;

void ParseIn () {
    ll curInt = 0;
    Boot solo;

    ifstream inFile ("snowboots.in");

    inFile >> _maxSnow >> _maxBoot;

    for (int i = 0; i < _maxSnow; i++) {
        inFile >> curInt;

        _snowList.push_back(curInt);   
    }

    for (int i = 0; i < _maxBoot; i++) {
        inFile >> solo._depth >> solo._range;
        solo._index = i;

        _bootList.push_back(solo);
        _resList.push_back(0);
    }

    inFile.close();
}

bool CompBootDepthDown (Boot a, Boot b) {
    return a._depth > b._depth;
}

bool CompByIndexDown (ll a, ll b) {
    return _snowList[a] > _snowList[b];
}

void Core () {
    vector<ll> tileIndex;

    for (int i = 1; i < _maxSnow-1; i++) {tileIndex.push_back(i);} //given that first and last element are 0

    sort(tileIndex.begin(), tileIndex.end(), CompByIndexDown);
    sort(_bootList.begin(), _bootList.end(), CompBootDepthDown);

    ll deepestSnow = 0;
    ll minRange = 0;

    set<ll> validSnow;

    for (int i = 0; i < _maxSnow; i++) {validSnow.insert(i);}

    for (auto boot : _bootList) {

        //removing tiles this boot cannot go through (list is sorted, so no need to refresh set)
        // tileIndex[deepestSnow] basically gives the index of the deepest snow
        while (deepestSnow < _maxSnow - 2 && _snowList[tileIndex[deepestSnow]] > boot._depth) {
            auto toRemove = validSnow.find(tileIndex[deepestSnow]);

            minRange = max(minRange, *next(toRemove) - *prev(toRemove));

            validSnow.erase(toRemove);
            deepestSnow++;
        }

        if (boot._range > minRange - 1) {_resList[boot._index] = 1;}
        //all elements of resList are already set to 0
    }
    
}

void CWriteOut () {
    ofstream outFile ("snowboots.out");

    for (int i = 0; i < _resList.size(); i++) {
        outFile << _resList[i] << endl;
    }

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
