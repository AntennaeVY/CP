#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<pair<int,int>> p(n);
		for(auto &[px, py] : p) cin >> px >> py;
		
		sort(p.begin(), p.end());
		
		bool ok = true;
		int x = 0, y = 0;
		string ans = "";
		
		for(auto &[px, py] : p) {
			if (px - x < 0 || py - y < 0) {
				ok = false;
				break;
			}	
			
			ans += string(px-x, 'R');
			ans += string(py-y, 'U');
			
			x = px;
			y = py;
		} 
		
		cout << (ok ? "YES\n"+ans : "NO") << endl;
	}
}