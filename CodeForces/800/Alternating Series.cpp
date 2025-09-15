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
		
		for(int i=0; i < n-1; i++) {
			cout << (i % 2 == 0 ? -1 : 3) << " ";
		}
		
		if (n % 2 == 0)
			cout << 2 << "\n";
		else
			cout << -1 << "\n";
	}
}