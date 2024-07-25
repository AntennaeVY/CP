#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<string> v(n);
		int mx = 0, x = 0, y = 0;
		
		for(int i=0; i < n; i++) {
			cin >> v[i];
			
			int cnt = count(v[i].begin(), v[i].end(), '#');
			
			if (cnt > mx)
				mx = cnt, x = i;
		}
		
		int sum = 0;
		
		for(int i=0; i < v[x].size(); i++) {
			sum += (v[x][i] == '#');
			
			if (sum == (mx+1)/2) {
				y = i;
				break;
			}
		}
		
		cout << x+1 << " " << y+1 << endl;
	}
}