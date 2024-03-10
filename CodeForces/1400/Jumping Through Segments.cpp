#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> L(n), R(n);
		
		for(int i=0; i < n; i++) {
			cin >> L[i] >> R[i];
		}
		
		int l=-1, r=1e9;
		while(l + 1 < r) {
			int mid = l + (r-l)/2;
			
			bool can = true;
			int start = 0, end = mid;
			
			for(int i=0; i < n; i++) {
				if (max(L[i], start) > min(R[i], end)) {
					can = false;
					break;
				}
				
				start = max(L[i], start) - mid;
				end = min(R[i], end) + mid;
			}
			
			if (can)
				r = mid;
			else
				l = mid;
		}
		
		cout << r << endl;
	}
}