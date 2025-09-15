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
		
		int x = 0, y = 0;
		long long ans = 0;
		for(int i=0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			
			if (y == b) {
				ans += (a-x) % 2 == 0 ? a-x : a-x-1;
			} else {
				ans += (a-x) % 2 == 1 ? a-x : a-x-1;
			}
			
			x = a;
			y = b;
		}
		
		cout << ans + (m-x) << "\n";
	}
}