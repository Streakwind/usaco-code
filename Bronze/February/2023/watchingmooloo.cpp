#define ll long long

#include <bits/stdc++.h>
using namespace std;

int main() {
	ll N = 0;
	ll K = 0;
	vector<ll> myList;

	cin >> N >> K;

	myList.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> myList[i];
	}

	ll ideal = 0;

	for (int i = 0; i < N; i++) {
		//cout << myList[i] << ", " << lastEnd << endl;
		if (i == 0) {ideal += (K+1); continue;}

		if (myList[i]-myList[i-1] < K+1) {ideal += (myList[i]-myList[i-1]);} //continue interval
		else {ideal += (K+1);} //start a new interval
	}

	cout << ideal << endl;

	return 0;
}
