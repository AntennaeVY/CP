#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(2*n);
		for(auto &ai : a) cin >> ai;
		
		int odd = 0;
		
		for(int i=0; i < 2*n; i++) {
			odd += a[i] % 2; 
		}
		
		cout << (odd == n ? "YES" : "NO") << endl;
	}
}