#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), ans(n, -1e9);
		for(auto &ai : a) cin >> ai;
		
		priority_queue<int, vector<int>, greater<int>> pq;
		
		for(int i=0; i < n; i++) {
			int l;
			cin >> l;
			
			if (l)
				ans[i] = a[i];
			else
				pq.push(a[i]);
		}
		
		for(int i=n-1; i >= 0; i--) {
			if (ans[i] == -1e9) {
				ans[i] = pq.top();
				pq.pop();
			}
		}
		
		for(auto ansi : ans) cout << ansi << " ";
		
		cout << endl;
	}
}