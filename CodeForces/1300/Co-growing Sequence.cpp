#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> x(n);
		for(auto &xi:x) cin >> xi;
		
		vector<int> ans(n, 0);
		
		for(int i=1; i < n; i++) {
			ans[i] = (x[i-1] ^ ans[i-1]) & (~x[i]);	
		}
		
		for(auto y : ans) {
			cout << y << " ";
		}
		
		cout << endl;
	}
}