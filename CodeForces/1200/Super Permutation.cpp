#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;
		
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		
		if ((1LL*n*(n+1)/2) % n == 0) {
			cout << -1 << endl;
			continue;
		}
		
		vector<int> ans(n);
		ans[0] = n;
		
		int l = n-1, r = 1;
		
		for(int i=1; i < (n/2) + 1; i++) {
			
			if (i % 2) {
				ans[i] = l;
				ans[n-i] = r;	
			} else {
				ans[i] = r;
				ans[n-i] = l;
			}
			
			l--, r++;
		}
		
		for(auto &ansi : ans)
			cout << ansi << " ";
			
		cout << endl;
	}
}