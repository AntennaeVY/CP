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

		int ans = 0, cnt = 0;
		long long sum = 0;

		for(int i=0; i < n; i++) {
			if (a[i] < 0)
				cnt++;
			else if (a[i] > 0) 
				ans += (cnt != 0), cnt = 0;

			sum += abs(a[i]);
		}

		ans += (cnt != 0);
		
		cout << sum << " " << ans << endl;
	}
}