#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		vector<pair<int, int>> diff;
		
		for(int i=0; i < n; i++) {
			diff.emplace_back(a[i] - b[i], i+1);
		}
		
		sort(diff.rbegin(), diff.rend());
		
		vector<int> ans;
		
		for(int i=0; i < n; i++) {
			if (diff[i].first == diff[0].first)
				ans.push_back(diff[i].second);
		}
		
		sort(ans.begin(), ans.end());
		
		cout << ans.size() << endl;
		
		for(auto &ansi : ans) 
			cout << ansi << " ";
			
		cout << endl;
	}
}