#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(auto &ai : a) cin >> ai;

		int even = 0, odd = 0, bad = 0;
		for(int i=0; i < n; i++) {
			odd += a[i] % 2;
			even += !(a[i] % 2);

			bad += (a[i] % 2 != i % 2);
		}

		if (odd != n/2)
			cout << -1 << endl;
		else
			cout << bad/2 << endl;
	}
}