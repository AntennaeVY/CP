#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, l, r;
		cin >> n >> m >> l >> r;
		
		int d = (n-m);
		
		while(d) {
			if (l < 0)
				l++;
			else if (l > 0)
				l--;
			else if (r > 0)
				r--;
			else if (r < 0)
				r++;
				
			d--;
		}
		
		cout << l << " " << r << endl;
	}
}