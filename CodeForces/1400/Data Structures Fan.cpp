#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		string s;
		cin >> s;
		
		int q;
		cin >> q;
		
		int x0 = 0, x1 = 0;
		vector<int> p(n+1, 0);
		
		for(int i=0; i < n; i++) {
			if (s[i] == '0')
				x0 ^= a[i];
			else
				x1 ^= a[i];
				
			p[i+1] = p[i] ^ a[i];
		}
		
		while(q--) {
			int tp;
			cin >> tp;
			
			if (tp == 1) {
				int l, r;
				cin >> l >> r;
				
				x0 ^= (p[r] ^ p[l-1]), x1 ^= (p[r] ^ p[l-1]);
			} else if (tp == 2) {
				int g;
				cin >> g;
				
				cout << (g ? x1 : x0) << " ";
			}
		}
		
		cout << endl;
	}
}