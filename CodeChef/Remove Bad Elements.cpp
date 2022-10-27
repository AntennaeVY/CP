#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int,int> m;
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			m[x]++;
			
			ans = max(ans, m[x]);
		}
		
		cout << n - ans << endl;
	}
}