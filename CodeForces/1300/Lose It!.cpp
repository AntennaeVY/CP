#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	map<int, vector<int>> m;
	for(int i=0; i < n; i++) {
		m[a[i]].push_back(i);
	}
	
	int ans = 0;
	
	while(true) {
		if (m[4].empty())
			break;
			
		int prev = m[4].back();
		bool empty = false;
		
		for(int x : {8, 15, 16, 23, 42}) {
			while(!m[a[prev]].empty() && !m[x].empty() && m[x].back() < prev ) {
				m[a[prev]].pop_back();
				
				if (!m[a[prev]].empty())
					prev = m[a[prev]].back();
		
				ans++;
			}
				
			if (m[a[prev]].empty() || m[x].empty()) {
				empty = true;
				break;
			}
			
			prev = m[x].back();
		}
		
		if (empty)
			break;
		
		for(int x : {4, 8, 15, 16, 23, 42}) {
			m[x].pop_back();
		}
	}
	
	for(auto &[x, v] : m) {
		ans += v.size();
	}
	
	cout << ans << endl;
	
}