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
		
		vector<int> cnt(2e5 + 10);
		for(int i=0; i < n; i++) {
			cnt[a[i]]++;
		}
		
		vector<int> ans;
	
		for(int i=1; i <= n; i++) {
			if (cnt[i] == 0) {
				ans.push_back(i);
			}
		}
		
		if (ans.size() == 0) {
			ans.push_back(a[0]);
			ans.push_back(a[1]);
			ans.push_back(a[2]);
		} else if (ans.size() < 3) {
			for(int i=0; i < n-1; i++) {
				if (ans.size() == 1 && a[i] != a.back())
					ans.push_back(a[i]);
			}
			
			ans.push_back(a.back());
		}
		
		int x=0;
		while(ans.size() && ans.size() < k) {
			ans.push_back(ans[x]);
			
			x++, x %= 3;
		}
		
		for(int i=0; i < k; i++) {
			cout << ans[i] << " ";
		}
		
		cout << "\n";
	}
}