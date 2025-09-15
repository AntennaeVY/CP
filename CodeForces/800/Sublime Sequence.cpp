#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int x, n;
		cin >> x >> n;
		
		cout << (n % 2 ? x : 0) << "\n";
	}
}