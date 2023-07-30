#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, k, x;
		cin >> n >> k >> x;
		
		if (x == 1 && (k == 2 && n % 2 || k == 1)) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			
			if (x != 1){
				cout << n << endl;
		
				for(int i=0; i < n; i++)
					cout << 1 << " ";
			} else if (n % 2) {
				cout << n/2 << endl;
				
				cout << 3 << " ";
				while(n-3) {
					cout << 2 << " ";
					n -= 2;
				}
			} else {
				cout << n/2 << endl;
				
				for(int i=0; i < n/2; i++) {
					cout << 2 << " ";
				}
			}
		
			cout << endl;
		}
	}
}