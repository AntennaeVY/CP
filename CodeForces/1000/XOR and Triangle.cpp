#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int x;
		cin >> x;
		
		int y = (1 << __lg(x)) - 1;
		int z = (x ^ y);
		
		if (x+y > z && x+z > y && y+z > x) {
			cout << y << endl;
		} else {
			cout << -1 << endl;
		}
	}
}