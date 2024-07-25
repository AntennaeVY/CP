#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int x, y;
		cin >> x >> y;
		
		int xf, yf;
		cin >> xf >> yf;
		
		if (x > y && yf >= xf || y > x && xf >= yf)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}