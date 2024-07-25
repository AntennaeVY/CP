#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<int> p(n+1);
	for(int i=0; i < n; i++) {
		p[i+1] = p[i] + a[i];
	}
	
	int m;
	cin >> m;
	
	while(m--) {
		int q;
		cin >> q;
	
		int ans = -1;
		
		int l=0, r=n+1;
		while(l + 1 < r) {
			int x = l + (r-l) / 2;
			
			if (q >= p[x-1] + 1 && q <= p[x]) {
				ans = x;
				break;
			}
			
			if (q > p[x])
				l = x;
			else
				r = x;
		}
		
		cout << ans << endl;
	}
}