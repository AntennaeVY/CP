#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,x,y,n;
		cin >> a >> b >> x >> y >> n;
		
		int p = min(a-x, n);
		int q = min(b-y, n);
		
		cout << min(1LL*(a-p)*(b-min(n-p, b-y)), 1LL*(b-q)*(a-min(n-q, a-x))) << endl;
	}
}