#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_M=2*1e5+3;
vector<vector<int>> st(25, vector<int>(MAX_M, 0));

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(m);
	for(auto &ai : a) cin >> ai;
	
	for(int i=1; i <= m; i++) {
		st[0][i] = a[i-1];	
	}
	
	for(int i=1; i < 25; i++) {
		for(int j=1; j + (1 << i) <= m+1; j++) {
			st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
		}
	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int k;
		cin >> k;
		
		int moveX = x2 - x1;
		int moveY = y2 - y1;
		
		if (moveX % k || moveY % k) {
			cout << "NO" << "\n";
			continue;
		}
	
		int minRow = n - (n-x1) % k;
		
		// check that there are no blocked cells in minRow in range [y1, y2]
		int p = __lg(abs(y2-y1)+1);
		int p2 = (1 << p);
		
		int maxBlocked = 0;
		
		if (moveY < 0)
			maxBlocked = max(st[p][y2], st[p][y1-p2+1]);
		else
			maxBlocked = max(st[p][y1], st[p][y2-p2+1]);
		
		if (maxBlocked >= minRow) {
				cout << "NO" << "\n";
				continue;
			}
			
		cout << "YES" << "\n";	
	}
}