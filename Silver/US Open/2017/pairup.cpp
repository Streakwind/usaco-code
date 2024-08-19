#define ll long long

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	ll maxi = 0;
    ll amt = 0, curll = 0;
    ll res = 0;
    vector<pair <ll, ll>> cowList;

	ifstream inFile ("pairup.in");

	inFile >> maxi;

	for (ll i = 0; i < maxi; i++) {
        inFile >> amt >> curll;

        cowList.push_back(make_pair(curll, amt));
    }

    inFile.close();

    sort (cowList.begin(), cowList.end());

    ll pt1 = 0, pt2 = 0;
    ll bigGroup = 0;

    pt1 = 0;
    pt2 = cowList.size() - 1;

    while (pt1 < pt2+1) {
        bigGroup = min(cowList[pt1].second, cowList[pt2].second);
        if (pt1 == pt2) {bigGroup /= 2;}

        res = max(res, cowList[pt1].first + cowList[pt2].first);

        cowList[pt1].second -= bigGroup;
        cowList[pt2].second -= bigGroup;

        if (cowList[pt1].second == 0) {
            pt1++;
        }

        if (cowList[pt2].second == 0) {
            pt2--;
        }

        cout << res << endl;
    }

    ofstream outFile ("pairup.out");

    outFile << res << endl;

    outFile.close();

	return 0;
}
