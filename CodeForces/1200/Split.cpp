#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int,int> cnt;
		for(int i=0; i < n; i++) {
			cnt[a[i]]++;
		}
		
		bool ok = true;
		
		for(auto [v, c] : cnt) {
			if (c % k != 0)
				ok = false;
		}
		
		if (!ok) {
			cout << "0\n";
			continue;
		}
		
		multiset<int> ms;
		for(auto [v, c] : cnt) {
			for(int i=0; i < c/k; i++)
				ms.insert(v);
		}
		
		long long ans = 0;
		map<int, int> have;
		
		int l=0;
		for(int r=0; r < n; r++) {
			have[a[r]]++;
			
			while(have[a[r]] > cnt[a[r]] / k) {
				have[a[l++]]--;
			}
	
			ans += (r-l+1);
		}
		
		cout << ans << "\n";
	}
}