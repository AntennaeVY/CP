#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, l, r;
		cin >> n >> l >> r;
		
		vector<int> c(n);
		for(auto &ci:c) cin >> ci;
		
		map<int, int> left, right;
		
		for(int i=0; i < n; i++) {
			if (i < l)
				left[c[i]]++;
			else
				right[c[i]]++;
				
		}
		
		for(int i=0; i < n; i++) {
			int amt = min(left[c[i]], right[c[i]]);
			
			left[c[i]] -= amt;
			right[c[i]] -= amt;
		}
		
		int ans = 0;
		int cnt_left = 0, cnt_right = 0;
		
		for(auto x : left)
			cnt_left += x.second;
			
		for(auto x : right) 
			cnt_right += x.second;
		
		for(auto [_, cnt] : left) {
			if (cnt_left <= cnt_right)
				break;
				
			int amt = min(cnt_left - cnt_right, cnt - (cnt % 2));
			cnt_left -= amt;
			
			ans += amt/2;
		}
		
		for(auto [_, cnt] : right) {
			if (cnt_right <= cnt_left)
				break;
				
			int amt = min(cnt_right - cnt_left, cnt - (cnt % 2));
			cnt_right -= amt;
			
			ans += amt/2;				
		}
		
		ans += abs(cnt_left - cnt_right) / 2;
		ans += (cnt_left + cnt_right) / 2;
		
		cout << ans << endl;
	}
}