#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n*n);
	for(auto &ai : a) cin >> ai;
	
	map<int, int> m;
	for(auto &ai : a) m[ai]++;
	
	priority_queue<pair<int, int>> q;
	for(auto &[ai, c] : m) q.push({c, ai});
	
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	
	for(int i=0; i < n/2; i++) {
		for(int j=0; j < n/2; j++) {
			auto x = q.top();
			q.pop();
			
			if (x.first < 4) {
				cout << "NO" << endl;
				exit(0);
			}
			
			matrix[i][j] = x.second;
			matrix[i][n-1-j] = x.second;
			matrix[n-1-i][j] = x.second;
			matrix[n-1-i][n-1-j] = x.second;
			
			x.first -= 4;
			
			if (x.first)
				q.push(x);
		}	
	}
	
	if (n & 1) {
		for(int i=0; i < n/2; i++) {
			auto x = q.top();
			q.pop();
			
			if (x.first < 2) {
				cout << "NO" << endl;
				exit(0);
			}
			
			matrix[i][n/2] = x.second;
			matrix[n-1-i][n/2] = x.second;
			
			x.first -= 2;
			
			if (x.first)
				q.push(x);
		}
		
		for(int j=0; j < n/2; j++) {
			auto x = q.top();
			q.pop();
			
			if (x.first < 2) {
				cout << "NO" << endl;
				exit(0);
			}
			
			matrix[n/2][j] = x.second;
			matrix[n/2][n-1-j] = x.second;
			
			x.first -= 2;
			
			if (x.first)
				q.push(x);
		}
		
		matrix[n/2][n/2] = q.top().second;
	}
	
	
	cout << "YES" << endl;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			cout << matrix[i][j] << " \n"[j == n-1];
		}
	}
}