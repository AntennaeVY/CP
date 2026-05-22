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
		
		vector<int> w(n);
		for(auto &wi : w) cin >> wi;
		
		vector<int> cnt(3);
		for(int i=0; i < n; i++)
			cnt[w[i]] += 1;
			
		int ans = cnt[0];
		int mn =  min(cnt[1], cnt[2]);
		
		ans += mn;
		cnt[1] -= mn, cnt[2] -= mn;
		
		ans += cnt[1] / 3 + cnt[2] / 3;
		
		cout << ans << endl;
	}
}