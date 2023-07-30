#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ones = 0;
		vector<vector<char>> polygon(n, vector<char>(n));
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				cin >> polygon[i][j];
				
				if (polygon[i][j] == '1')
					ones++;
			}
		}
		
		map<pair<int,int>, bool> visited;
		function<int(int, int)> up_and_left;
		
		up_and_left = [&](int i, int j) {
			if (i == -1 || j == -1 || visited[{i, j}])
				return 0;
				
			visited[{i, j}] = true;
		
			if (polygon[i][j] == '0')
				return 0;
	
			int ans = 1 + up_and_left(i-1, j) + up_and_left(i, j-1);
			return ans;
		};
		
		int cnt = 0;
		
		for(int j=n-1; j >= 0; j--) {
			cnt += up_and_left(n-1, j);
		}
		
		for(int i=n-1; i >= 0; i--) {
			cnt += up_and_left(i, n-1);
		}
		
		cout << (cnt == ones ? "YES" : "NO") << endl;
	}
}