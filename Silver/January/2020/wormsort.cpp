

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // PARSE DATA
    ifstream fin("wormsort.in");

    int cowNum, whNum;
    int maxWeight = 0;
    int correctPlace = 0;
    int prevCow = -1;

    fin >> cowNum >> whNum;

    vector<int> cows(cowNum);
    vector<vector<pair<int,int>>> whs(whNum);

    for (int &cow : cows) {
        fin >> cow; cow--;

        if (cow == prevCow+1) correctPlace++;
        prevCow = cow;
    }

    if (correctPlace == cowNum) {
        ofstream fout("wormsort.out");
        fout << -1 << endl;
        fout.close();
        return 0;
    }

    int start, end, weight;

    for (int i = 0; i < whNum; i++) {
        fin >> start >> end >> weight;
        start--; end--;
        whs[start].push_back({end, weight});
        whs[end].push_back({start, weight});
        maxWeight = max(maxWeight, weight);
    }

    fin.close();

    // BINARY SEARCH ON VALID WEIGHT
    int res = 0;
    int l = 0, r = maxWeight+1;

    while (l < r+1) {
        int compNum = 0;
        int m = l + (r-l)/2;

        vector<int> components(cowNum, -1);

        for (int i = 0; i < cowNum; i++) {
            if (components[i] != -1) continue;

            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                components[cur] = compNum;

                for (const auto &[n, w] : whs[cur]) {
                    if (components[n] == -1 && w >= m) q.push(n);
                }
            }

            compNum++;
        }

        bool sortable = true;

        for (int i = 0; i < cowNum; i++) {
            if (components[i] != components[cows[i]]) {sortable=false; break;}
        }

        if (sortable) {
            res = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    // OUTPUT DATA
    ofstream fout("wormsort.out");
    fout << res << endl;
    fout.close();

    return 0;
}
