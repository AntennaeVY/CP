#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int k;
		cin >> k;
		
		cout << (k % 2 ? "YES" : "NO") << endl;
	}
}