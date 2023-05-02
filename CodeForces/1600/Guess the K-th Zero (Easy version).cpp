#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	
	while(t--) {
		int k;
		cin >> k;
		
		int l = 0, r = n;
		while(r-l > 1) {
			int mid = l + (r-l)/2;
		
			cout << "? 1 " << mid << endl; 
		
			int ans; 
			cin >> ans;
			
			if (mid - ans >= k)
				r = mid;
			else
				l = mid;	
		}
		
		cout << "! " <<  r << endl;
	}
}