#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		
		if (a > b)
			swap(a, b);
			
		if (b > 2*a) {
			cout << "NO\n";
			continue;
		}
		
		if (2*a % 3 == b % 3)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}