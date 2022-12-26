#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int neg = 0, pos = 0;
		vector<int> a(n);
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			
			neg += (a[i] < 0);
			pos += (a[i] > 0);
		}
		
		if ((pos+neg)%2) {
			cout << -1 << endl;
			continue;
		}
		
		if (pos == neg) {
			cout << n << endl;
			for(int i=1; i <= n; i++)
				cout << i << " " << i << endl;
				
			continue;
		}
		
		vector<pair<int,int>> ans;
		
		for(int i=0; i < n-1; i++) {
			if (pos > neg && a[i+1] == 1) {
				ans.push_back({i+1, i+2});
				pos -= 1;
				neg += 1;
				i++;
			} else if (neg > pos && a[i+1] == -1) {
				ans.push_back({i+1, i+2});
				neg -= 1;
				pos += 1;
				i++;
			} else {
				ans.push_back({i+1, i+1});
			}
		}
		
		if (ans.back().second != n) {
			ans.push_back({n, n});
		}
		
		cout << ans.size() << endl;
		
		for (auto x : ans) {
			cout << x.first << " " << x.second << endl;
		}
	}
}