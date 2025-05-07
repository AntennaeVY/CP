#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> a(n, vector<int>(m));
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		
		long long total = 0;
		
		vector<int> sum(n, 0);
		for(int i=0; i < n; i++) {
			sum[i] = accumulate(a[i].begin(), a[i].end(), 0);
			total += sum[i];
		}
		
		if (total % n != 0) {
			cout << -1 << endl;
			continue;
		}
		
		total /= n;

		vector<vector<int>> ans;

		for(int j=0; j < m; j++) {
			vector<int> v0, v1;
			
			for(int i=0; i < n; i++) {
				if (sum[i] > total && a[i][j] == 1) v1.push_back(i);
				if (sum[i] < total && a[i][j] == 0) v0.push_back(i);
			}
			
			for(int i=0; i < min(v0.size(), v1.size()); i++) {
				sum[v0[i]]++, sum[v1[i]]--;
				swap(a[v0[i]][j], a[v1[i]][j]);
				
				ans.push_back({v0[i]+1, v1[i]+1, j+1});
			}
		}
		
		cout << ans.size() << endl;
		
		for(auto &ansi : ans){
			for(auto &ansij : ansi)
				cout << ansij << " ";
			cout << endl;
		}
	}
}