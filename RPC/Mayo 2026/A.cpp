#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long double x;
		cin >> x;
		
		long double y = x + 0.005;
		
		long double dx = x / 0.015, dy = y / 0.015;
		
		if (dx - (int)dx < 1e-6 || dy - (int)dy < 1e-6)
			cout << "VALID\n";
		else
			cout << "IMPOSSIBLE\n";
	}
}