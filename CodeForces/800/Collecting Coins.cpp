#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,c,n;
		cin >> a >> b >> c >> n;
		
		int mx = max(a, max(b, c));
		int diff_a = mx - a, diff_b = mx - b, diff_c = mx - c;
		int tot = diff_a + diff_b + diff_c;
		
		if (n - tot >= 0 && (n-tot)%3 == 0)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}