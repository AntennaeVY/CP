#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int l,r,d,u;
		cin >> l >> r >> d >> u;
		
		vector<int> a = {l, r, d, u};
		
		if (count(a.begin(), a.end(), a[0]) == 4)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
}