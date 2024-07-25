#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, c;
		cin >> n >> c;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		int l=0, r=1e9+5;
		while(l+1 < r) {
			int x = l + (r-l)/2;
			
			int last = a[0], cnt = 1;
			
			for(int i=1; i < n; i++) {
				if (a[i] - last >= x)
					last = a[i], cnt++;
			}
			
			if (cnt >= c)
				l = x;
			else
				r = x;
		}
		
		cout << l << endl;
	}
}