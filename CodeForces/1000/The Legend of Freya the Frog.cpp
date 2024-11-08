#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	for(int _=1; _ <= t; _++) {
		int x, y, k;
		cin >> x >> y >> k;

		if (x == 0 && y == 0) {
			cout << 0 << endl;
			continue;
		}
		
		int a = (x + k-1) / k;
		int b = (y + k-1) / k;
		
		cout << max(2*a - 1, 2*b) << endl;
	}
}