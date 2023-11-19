#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
		
		long long ans = 0, prev = 0;
		
		for(int i=1; i < n; i++) {
			long long ops = 0, curr = 0;
			long long x = a[i - 1], y = a[i];
			
		    if (a[i] >= a[i - 1]) {
    			while (x * 2 <= y) 
    				x *= 2, ops++;
    				
    			curr = max(0ll, prev - ops);
    		} else {
    			while (y < x) 
    				y *= 2, ops++;
    				
    			curr = prev + ops;
    		}
    		
    		ans += curr, prev = curr;
		}
		
		cout << ans << endl;
	}
}