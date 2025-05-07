#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	vector<vector<int>> cost(6, vector<int>(n+1));
	
	int x = 0;
	string abc = "abc";
	
	do {
		for(int i=0; i < n; i++) {
			cost[x][i+1] = cost[x][i] + (abc[i % 3] != s[i]);
		}
		
		x++;
	} while(next_permutation(abc.begin(), abc.end()));
	
	while(m--) {
		int l, r;
		cin >> l >> r;
		
		l--, r--;
		
		int ans = 1e9;
		
		for(int i=0; i < 6; i++) {
			ans = min(ans, cost[i][r+1] - cost[i][l]);
		}
		
		cout << ans << endl;
	}
}