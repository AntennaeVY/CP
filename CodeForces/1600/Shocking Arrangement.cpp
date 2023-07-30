#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), pos, neg;
		int mx = 0, mn = 0;
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			
			if (a[i] >= 0)
				pos.push_back(a[i]);
			else
				neg.push_back(a[i]);
			
			mx = max(a[i], mx);
			mn = min(a[i], mn);
		}
		
		if (find(a.begin(), a.end(), mx - mn) != a.end()) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		
		sort(neg.begin(), neg.end());
		sort(pos.rbegin(), pos.rend());
		
		int l = 0, r = 0, sum_l = 0, sum_r = 0;
		
		while(l < neg.size() && r < pos.size()) {
			if (sum_l <= sum_r) {
				cout << neg[l] << " ";
				
				sum_r += neg[l];
				sum_l -= neg[l++];
			} else {
				cout << pos[r] << " ";
				
				
				sum_l -= pos[r];
				sum_r += pos[r++];
			}
		}
		
		while(l < neg.size())
			cout << neg[l++] << " ";
		
		while(r < pos.size())
			cout << pos[r++] << " ";
			
		cout << endl;
	}
}