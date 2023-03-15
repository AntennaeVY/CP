#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x, y, n;
		cin >> x >> y >> n;
		
		for(int k=(n/x)*x; k >= 0; k-=x) {
			if (k+y <= n) {
				cout << k+y << endl;
				break;
			}
		}
	}
}