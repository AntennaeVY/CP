#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		int op = 0, last = 0;
		vector<int> ans(n, 1);
		
		for(int i=1; i < n; i++) {
			ans[a[i-1]-1] = i+1;
		}
		
		for(auto x : ans) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}