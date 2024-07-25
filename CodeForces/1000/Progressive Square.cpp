#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, c, d;
		cin >> n >> c >> d;
		
		int a11 = 1e9+1;
		map<int, int> m;
		
		for(int i=0; i < n*n; i++) {
			int x;
			cin >> x;
			
			m[x]++;
			a11 = min(a11, x);
		}
		
		vector<vector<int>> v(n, vector<int>(n));
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				v[i][j] = a11 + c*i + d*j;
				m[v[i][j]]--;
			}
		}
		
		bool can = true;
		
		for(auto &[x, cnt] : m) {
			can &= (cnt == 0);
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}