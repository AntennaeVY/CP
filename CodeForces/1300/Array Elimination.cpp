#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		vector<int> bits(30, 0);
		
		for(int i=0; i < 30; i++) {
			for(int j=0; j < n; j++) {
				bits[i] += !!(a[j] & (1 << i));
			}
		}
		
		for(int i=1; i <= n; i++) {
			bool ok = true;
			
			for(int j=0; j < 30; j++) {
				if (bits[j] % i != 0)
					ok = false;
			} 
			
			if (ok) 
				cout << i << " ";
		}
		
		cout << endl;
	}
}