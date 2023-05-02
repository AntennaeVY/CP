#include<bits/stdc++.h>
using namespace std;

int main() {  
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> a(n, vector<int>(m));
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	vector<vector<int>> lr(n, vector<int>(m)), gr(n, vector<int>(m)), lc(n, vector<int>(m)), gc(n, vector<int>(m));
	
	for(int i=0; i < n; i++) {
		vector<int> s;
		
		for(int j=0; j < m; j++) {
			s.push_back(a[i][j]);
		}
		
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		
		for(int j=0; j < m; j++) {
			lr[i][j] = lower_bound(s.begin(), s.end(), a[i][j]) - s.begin();
			gr[i][j] = s.size() - 1 - lr[i][j];
		}
	}
	
	for(int j=0; j < m; j++) {
		vector<int> s;
		
		for(int i=0; i < n; i++) {
			s.push_back(a[i][j]);
		}
		
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		
		for(int i=0; i < n; i++) {
			lc[i][j] = lower_bound(s.begin(), s.end(), a[i][j]) - s.begin();
			gc[i][j] = s.size() - 1 - lc[i][j];
		}
	}
	
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			int x = 1 + max(lr[i][j], lc[i][j]);
			
			cout << x + max(gr[i][j], gc[i][j]) << " ";
		}
		
		cout << '\n';
	}
}