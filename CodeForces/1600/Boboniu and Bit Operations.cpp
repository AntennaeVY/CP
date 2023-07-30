#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), b(m);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	for(int i=0; i < (1 << 9); i++) {
		bool ok = true;
		
		for(int j=0; j < n; j++) {
			bool can = false; 
			
			for(int k=0; k < m; k++) {
				int c = a[j] & b[k];
				can |= (c & i) == c;
			}

			ok &= can;
		}
		
		
		if (ok) {
			cout << i << endl;
			return 0;
		}
	}
}