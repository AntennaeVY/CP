#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		bool ok = false;
		
		for(ll i=0; n - i*2020 >= 0; i++) {
			if ((n - i*2020) % 2021 == 0)
				ok = true;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}