#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	while(q--) {
		int x;
		cin >> x;
		
		int l=-1, r=n-1;
		while(l+1 < r) {
			int m = l + (r-l)/2;
			
			if (a[m] >= x)
				r = m;
			else
				l = m;
		}
		
		if (a[r] != x)
			cout << -1 << "\n";
		else
			cout << r << "\n";
	}
}