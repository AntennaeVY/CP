#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<vector<int>> v;
	
	for(int i=0; i < n; i++) {
		int l=-1, r=v.size();
		
		while(l+1 < r) {
			int mid = l + (r-l)/2;
			
			if (v[mid].back() > a[i])
				l = mid;
			else
				r = mid;
		}
		
		if (r == v.size())
			v.push_back({a[i]});
		else 
			v[r].push_back(a[i]);
	}
	
	for(auto &u : v) {
		for(auto x : u) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}