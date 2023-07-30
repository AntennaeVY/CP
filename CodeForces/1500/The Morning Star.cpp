#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;

		map<int, int> x, y, dl, dr;		
		vector<pair<int, int>> p;
		
		for(int i=0; i < n; i++) {
			int pi, pj;
			cin >> pi >> pj;
			
			p.emplace_back(pi, pj);
			x[pi]++, y[pj]++, dl[pi+pj]++, dr[pi-pj]++;
		}
	
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			auto [pi, pj] = p[i];
			
			ans += x[pi] + y[pj] - 2;
			ans += dl[pi+pj] + dr[pi-pj] - 2;
		}
		
		cout << ans << endl;
	}
}