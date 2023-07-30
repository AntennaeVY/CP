#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		
		int lb = ((r-l+1)*(r-l+2))/2;
		int ub = (n*(n+1) - (n-r+l-1)*(n-r+l))/2;
		
		if (s > ub || s < lb) {
			cout << -1 << endl;
			continue;
		}
	
		vector<int> ans(n, 0);
		
		for(int i=n; i >= 1; i--) {
			if (r-l+1 == 0)
				break;
				
			lb = ((r-l)*(r-l+1))/2;
			ub = (i*(i-1) - (i-1-r+l)*(i-r+l))/2;
			
			if (s-i <= ub && s-i >= lb) {
				s -= i;
				ans[l-1] = i;
				l++;
			}
		}
		
		if (s > 0) {
			cout << -1 << endl;
			continue;
		}
			
		set<int> nums;
		for(int i=1; i <= n; i++) {
			nums.insert(i);
		}
		
		for(int i=0; i < n; i++) {
			nums.erase(ans[i]);
		}
		
		for(int i=0; i < n; i++) {
			if (ans[i] == 0) {
				ans[i] = *(nums.begin());
				nums.erase(*(nums.begin()));
			}
		}
		
		for(auto &x : ans) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}