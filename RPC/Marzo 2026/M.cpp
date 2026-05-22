#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int r, c;
	cin >> r >> c;
	
	if (c == 1) {
		cout << 1 << "\n";
		return 0;
	}
	
	if (r == 1) {
		cout << (c+2)/3 << "\n";
		return 0;
	}
	
	if (r > 2) {
		cout << -1 << "\n";
		return 0;
	}
	
	for(int i=2; i <= 1000; i++) {
		int x = 2*i - 1;
			
		if (x >= c) {
			cout << (x+1)/2 << "\n";
			return 0;
		}
	}
}