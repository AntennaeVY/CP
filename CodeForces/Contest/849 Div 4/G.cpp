#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, c;
		cin >> n >> c;
		
		vector<int> a(n);
		for(int i=1; i <= n; i++) {
			cin >> a[i-1];
			a[i-1] += i;
		}
		
		sort(a.begin(), a.end());
		
		int l=0, r=n+1;
		while(l+1 < r) {
			int x = l+(r-l)/2;
			
			long long cc = c;
			for(int i=0; i < x; i++) {
				cc -= a[i];
			}
			
			if (cc >= 0)
				l = x;
			else 
				r = x;
		}
		
		cout << l << endl;
	}
}