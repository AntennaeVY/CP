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

		sort(a.begin(), a.end());

		int ans = 0;
		for(int i=0; i < n/2; i++)
			ans += a[n-1-i] - a[i];
		
		cout << ans << endl;
	}
}