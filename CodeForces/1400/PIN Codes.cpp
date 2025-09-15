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
		
		vector<string> v(n);
		for(auto &si : v) cin >> si;
		
		map<string, int> m;
		for(int i=0; i < n; i++)
			m[v[i]]++;
			
		vector<string> ans;
			
		for(int i=0; i < n; i++) {
			if (m[v[i]] == 1)
				continue;
				
			m[v[i]]--;
			
			for(int j=0; j < 4; j++) {
				bool ok = false;
				
				for(int k=0; k < 10; k++) {
					v[i][j] = '0' + k;
					
					if (!m[v[i]]) {
						m[v[i]] += 1;
						ok = true;
						ans.push_back(v[i]);
						break;
					}
				}
				
				if (ok)
					break;
			}
		}
		
		cout << ans.size() << "\n";
		
		for(auto &ai : v)
			cout << ai << "\n";
		
	}
}