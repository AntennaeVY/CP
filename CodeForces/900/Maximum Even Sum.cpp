#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	while(t--) {
		long long a, b;
		cin >> a >> b;
		
		if (a*b % 2)
			cout << a * b + 1 << "\n";
		else if (a % 2 == 0 && b % 2 == 0|| (b % 4 == 0))
			cout << a * b/2 + 2 << "\n";
		else
			cout << -1 << "\n";
	}
}