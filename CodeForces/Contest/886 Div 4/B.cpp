#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int mx = 0, mx_i = -1;
		
		for(int i=0; i < n; i++) {
			int l, q;
			cin >> l >> q;
			
			if (l <= 10 && q > mx)
				mx = q, mx_i = i+1;
		}
		
		cout << mx_i << endl;
 	}
}