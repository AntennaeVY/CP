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
		
		int mn = 1e9, mx = -1;
		
		for(int i=1; i < n; i++) {
			int x = a[i], y = a[i-1];
			
			if (x == -1 && y == -1)
				continue;
				
			if (x == -1) {
				mn = min(mn, y);
				mx = max(mx, y);
			}
			
			if (y == -1) {
				mn = min(mn, x);
				mx = max(mx, x);
			}
		}
		
		int k = (mn+mx)/2;
		int maxima = 0;
		
		for(int i=1; i < n; i++) {
			int x = a[i], y = a[i-1];
			
			if (x == -1 && y == -1)
				continue;
				
			if (x == -1)
				maxima = max(maxima, abs(y-k));
				
			if (y == -1) 
				maxima = max(maxima, abs(x-k));
			
			if (x != -1 && y != -1)
				maxima = max(maxima, abs(x-y));
		}
		
		cout << maxima << " " << k << endl;
	}
}