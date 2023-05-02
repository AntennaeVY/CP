#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> a(n, vector<int>(n));
	long long sum = 0;
	
	for(auto &ai : a) {
		for(auto &aj : ai) {
			cin >> aj;
			sum += aj;
		}
	}
	
	int mn = 1e9+3;
	
	for(int i=0; i < n; i++) {
		mn = min(mn, a[i][n-1-i]);
	}
	
	cout << sum - mn << endl;
}