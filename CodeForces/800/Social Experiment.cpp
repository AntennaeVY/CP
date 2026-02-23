#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		if (n == 2 || n == 3) {
			cout << n << "\n";
			continue;
		}
		
		cout << n % 2 << "\n";
	}
}