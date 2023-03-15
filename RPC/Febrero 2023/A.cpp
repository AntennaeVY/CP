#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<int, bool> sieve;
	vector<int> primes;
	
	for(int i=2; i <= n; i++) {
		if (sieve[i])
			continue;
			
		primes.push_back(i);
		for(int j=i*i; j <= n; j+=i) {
			sieve[j] = true;
		}
	}
	
	vector<long long> dp(primes.size(), 0);
	dp[0] = 1;
	
	for(int i=1; i < primes.size(); i++) {
		for(int j=i-1; j >= 0 && primes[i] - primes[j] <= 14; j--) {
			dp[i] += dp[j];
		}
	}
	
	cout << dp.back() << endl;
}