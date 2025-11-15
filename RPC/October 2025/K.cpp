#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int c, n;
	cin >> c >> n;
	
	if (c > n) {
		cout << 0 << "\n";
	} else if (c == n) {
		cout << c << "\n";
	} else {
		cout << c+1 << "\n";
	}
}