#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int _=1; _ <= t; _++) {
		int n, m;
		cin >> n >> m;
		
		cout << "Scenario #" << _ << ": ";
		
		map<int, int> mp;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			mp[x]++;
		}
		
		for(int i=0; i < m; i++) {
			int x;
			cin >> x;
			
			cout << mp[x];
		}
		
		cout << endl;
	}
}