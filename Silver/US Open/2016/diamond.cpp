/*find max value starting from a certain lower bound, then find max value starting after the
previous max value using the list you just computed*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int N = 0, K = 0, curInt = 0;
    int res = 0;
    vector<int> diamondList;

    ifstream inFile ("diamond.in");

    inFile >> N >> K;

    //cout << N << K;

    for (int i = 0; i < N; i++) {
        inFile >> curInt;

        diamondList.push_back(curInt);
    }

    inFile.close();

    sort(diamondList.begin(), diamondList.end());

    vector<int> valBefore (N, 0);
    vector<int> valAfter (N+1, 0);

    int m = 0;

    for (int i = 0; i < N; i++) {
        while (m < N && diamondList[m] - diamondList[i] < K+1) {m++;} //m should not be reset

        valBefore[i] = m - i;
    }

    for (int i = N-1; i > -1; i--) {
        valAfter[i] = max(valAfter[i+1], valBefore[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << valBefore[i] << " " << valAfter[i + valBefore[i]] << endl;
        res = max(res, valBefore[i] + valAfter[i + valBefore[i]]);
    }

    ofstream outFile ("diamond.out");

    outFile << res;

    outFile.close();

    return 0;
}
