#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for(auto &si : s) cin >> si;
	
	int all = 0;
	vector<int> v(n);
	
	for(int j=0; j < m; j++) {
		int x = 0, y = 0;
		
		for(int i=0; i < n; i++) {
			if (s[i][j] == '1')
				x++;
			else
				y++;
		}
		
		if (x == 0 || y == 0)
			all++;
		else
			for(int i=0; i < n; i++) {
				if (s[i][j] == '1' && x < y || s[i][j] == '0' && y < x)
					v[i]++;
			}
	}
	
	int mx = *max_element(v.begin(), v.end());
	
	for(int i=0; i < n; i++) {
		if (v[i] == mx)
			cout << i+1 << " ";
	}
	cout << "\n";
}