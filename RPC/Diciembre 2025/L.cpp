#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int m;
		cin >> m;
		
		long long ans = 1, prev = 1;
		for(int i=1; i <= m; i++) {
			if(i % 2)
				ans += prev;
			else
				ans += 2*prev, prev = 2*prev;
		}
		
		
		cout << ans << endl;
	}
	
}