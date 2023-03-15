#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		map<int, int> deg;
		
		for(int i=0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			
			deg[u]++, deg[v]++;
		}
		
		if (deg[x] <= 1) {
			cout << "Ayush" << endl;
			continue;
		}
		
		if (n % 2 == 0) {
			cout << "Ayush" << endl;
		} else {
			cout << "Ashish" << endl;
		}
	}
}