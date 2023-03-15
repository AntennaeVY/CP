#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 2e9;
using ll = long long; 

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		
		for(ll i=0; i < MAX_N; i++) {
			ll sum = a + b + (i*(i+1))/2;
			
			if (sum >= 2LL*max(a,b) && sum % 2 == 0) {
				cout << i << endl;
				break;
			}
		}
	}
}