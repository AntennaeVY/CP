#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(n), b(n), c(m);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		for(auto &ci : c) cin >> ci;
		
		if (count(b.begin(), b.end(), c.back()) == 0) {
			cout << "NO" << endl;
			continue;
		}
		
		map<int, int> p;
		for(auto &ci : c) {
			p[ci]++;
		}
		
		bool can = true;
		
		for(int i=0; i < n; i++) {
			if (a[i] == b[i])
				continue;
				
			if (p[b[i]] == 0)
				can = false;
			
			p[b[i]]--;
		}
		
		if (!can) {
			cout << "NO" << endl;
			continue;
		} else {
			cout << "YES" << endl;
		}
		
		map<int, vector<int>> x, y;
		
		for(int i=0; i < n; i++) {
			if (a[i] != b[i])
				x[b[i]].push_back(i+1);
			else
				y[b[i]].push_back(i+1);
		}
		
		for(int i=0; i < m; i++) {
			if (x[c[i]].empty() && y[c[i]].empty())
				cout << (x[c.back()].empty() ? y[c.back()][0] : x[c.back()][0]) << " ";
			else if (x[c[i]].empty())
				cout << y[c[i]][0] << " ";
			else {
				cout << x[c[i]].back() << " ";
				y[c[i]].push_back(x[c[i]].back());
				x[c[i]].pop_back();
			}
		}
		
		cout << endl;
	}
}