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
		
		vector<int> b(n);
		for(auto &bi:b) cin >> bi;
		
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			if (a[i] > b[i])
				ok = false;
		}
		
		for(int i=0; i < n-1; i++) {
			if (b[i] > b[i+1] + 1 && b[i] != a[i]) 
				ok = false;
		}
		
		if (b[n-1] > b[0]+1 && a[n-1] != b[n-1])
			ok = false;		
			
		cout << (ok ? "YES" : "NO") << endl;
	}
}