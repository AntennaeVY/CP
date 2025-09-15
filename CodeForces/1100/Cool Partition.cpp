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
		
		vector<int> cnt(n+1, 0);
		for(int i=0; i < n; i++)
			cnt[a[i]]++;
		
		int ans = 0;
		
		set<int> need;
		set<int> has;
		
		for(int i=0; i < n; i++) {
			has.insert(a[i]);
		
			if (need.count(a[i]))
				need.erase(a[i]);
				
			if (need.empty()) {
				ans++;
				need = has;
			}
		}
		
		cout << ans << "\n";
	}
}