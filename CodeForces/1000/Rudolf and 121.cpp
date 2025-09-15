#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		bool bad = false;
		
		for(int i=0; i < n; i++) {
			if (a[i] < 0)
				bad = true;
			
			if (i+2 < n) {
				a[i+1] -= 2*a[i];
				a[i+2] -= a[i];
				a[i] = 0;				
			}
		}
		
		for(int i=0; i < n; i++)
			if (a[i] != 0)
				bad = true;	
		
		cout << (bad ? "NO" : "YES") << "\n";
	}
}