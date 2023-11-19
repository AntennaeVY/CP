#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int l=0, r=3e9;
		while(l+1 < r) {
			int m = l + (r-l)/2;
			
			long long cnt = 0;
			for(int i=0; i < n; i++) {
				cnt += max(0, m - a[i]);
			}
			
			if (cnt <= x)
				l = m;
			else
				r = m;
		}
		
		cout << l << endl;
	}
}