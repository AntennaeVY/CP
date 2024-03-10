#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int xa, ya;
		cin >> xa >> ya;
		
		int xb, yb;
		cin >> xb >> yb;
		
		int xf, yf;
		cin >> xf >> yf;
		
		int ans = abs(xa - xb) + abs(ya -  yb);
		
		if ((xa == xb && xb == xf && (yf > yb && yf < ya || yf < yb && yf > ya)) || ya == yb && yb == yf && (xf < xa && xf > xb || xf > xa && xf < xb))
			ans += 2;
		
		cout << ans << endl;
	}
}