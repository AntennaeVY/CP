#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		int g = 0, ans = 0;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (x >= k)
				g += x;
			else if (g > 0 && x == 0)
				g -= 1, ans++;
		}
		
		cout << ans << endl;
	}
}