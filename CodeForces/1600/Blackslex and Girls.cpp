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
		
		int x, y;
		cin >> x >> y;
		
		string s;
		cin >> s;
		
		vector<int> p(n);
		for(auto &pi : p) cin >> pi;
		
		long long sum = accumulate(p.begin(), p.end(), 0LL);
		long long tx = x, ty = y;
		bool win_a = false, win_b = false;
		
		if (x + y < sum) {
			cout << "NO\n";
			continue;
		}
		
		for(int i=0; i < n; i++) {
			if (s[i] == '0') {
				tx -= p[i] / 2 + 1;
				
				win_a = true;
			} else { 
				ty -= p[i] / 2 + 1;
				
				win_b = true;
			}
		}
		
		if (tx < 0 || ty < 0) {
			cout << "NO\n";
			continue;
		}
		
		if (!win_a) {
			if (y < x + n) {
				cout << "NO\n";
				continue;
			}
		}
		
		if (!win_b) {
			if (x < y + n) {
				cout << "NO\n";
				continue;
			}
		}
	
		cout << "YES\n";
	}
}