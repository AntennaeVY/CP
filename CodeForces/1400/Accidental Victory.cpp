#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, vector<int>> m;
		map<int, bool> can;
		vector<int> a, ans;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (m[x].size() == 0)
				a.push_back(x);
				
			m[x].push_back(i+1);
		}
		
		sort(a.begin(), a.end());
		can[a.back()] = true;
		ans.insert(ans.end(), m[a.back()].begin(), m[a.back()].end());
		
		vector<long long> prefix_sum(a.size()+1, 0);
		
		for(int i=1; i < prefix_sum.size(); i++) {
			prefix_sum[i] = prefix_sum[i-1] + 1LL*a[i-1]*m[a[i-1]].size();
		}
		
		for(int i=a.size()-2; i >= 0; i--) {
			if (prefix_sum[i+1] >= a[i+1] && can[a[i+1]]) {
				can[a[i]] = true;
				ans.insert(ans.end(), m[a[i]].begin(), m[a[i]].end());
			}
		}
		
		sort(ans.begin(), ans.end());
		
		cout << ans.size() << endl;
		
		for(auto x : ans) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}