#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		long long ans = 0;
		
		vector<int> v;
		for(int i=0; i < n; i++) {
			if (a[i] % 2)
				v.push_back(a[i]);
			else
				ans += a[i];
		}
		
		sort(v.rbegin(), v.rend());
		
		int j = 0;
		for(int i=0; i < v.size(); i+=2, j++) {
			ans += v[j];
		}
		
		if (v.size())
			cout << ans << "\n";
		else
			cout << "0\n";
	}
}