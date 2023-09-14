#include<bits/stdc++.h>
using namespace std;

const int MAX_X = 1e7 + 10;

vector<bool> isPrime(MAX_X, true);
vector<int> g(MAX_X, 1);

int main() {
	for(int i=4; i < MAX_X; i += 2) {
		isPrime[i] = false; 
		g[i] = 2;
	}
	
	for(int i=3; i < MAX_X; i += 2) {
		if (!isPrime[i])
			continue;
			
		for(long long j=1LL*i*i; j < MAX_X; j += i) {
			// first time seeing this composite number
			if (isPrime[j])
				g[j] = i;
			
			isPrime[j] = false;
		}
	}
	
	int t;
	cin >> t;
	
	while(t--) {
		int l, r;
		cin >> l >> r;
		
		bool ok = false;
		
		for(int i=l; i <= r; i++) {
			if (!isPrime[i]) {
				cout << g[i] << " " << i - g[i] << endl;
				ok = true;
				break;
			}
		}
		
		if (!ok)
			cout << -1 << endl;
	}
}