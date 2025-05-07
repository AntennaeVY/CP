#include<bits/stdc++.h>
using namespace std;

constexpr int SIEVE_MAX = 4e5+2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<bool> is_prime(SIEVE_MAX+2, true);
	is_prime[0] = is_prime[1] = false;
	
	for(long long i=2; i <= SIEVE_MAX; i++) {
		if (!is_prime[i])
			continue;
		
		for(long long j=i*i; j <= SIEVE_MAX; j+=i) {
			is_prime[j] = false;
		}
	}
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int a = -1, b = -1;
		for(int i=1; 2*i - 1 <= n; i++) {
			if (a != -1 && b != -1)
				break;
			
			for(int j=1; 2*j <= n; j++) {
				if (!is_prime[2*i - 1 + 2*j]) {
					a = 2*i - 1, b = 2*j;
					break;
				}
			}
		}
		
		if (a == -1 && b == -1) {
			cout << -1 << endl;
			continue;
		}
		
		for(int i=1; 2*i - 1 <= n; i++) {
			if (2*i - 1 != a)
				cout << 2*i - 1 << " ";
		}
		
		cout << a << " " << b << " ";
		
		for(int i=1; 2*i <= n; i++) {
			if (2*i != b)
				cout << 2*i << " ";
		}
		
		cout << endl;
	}
	
}