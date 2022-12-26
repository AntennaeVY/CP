#include<bits/stdc++.h>
using namespace std;

bool is_valid(long long x) {
	map<long long, long long> cnt;
	
	for(long long i=2; i*i <= x; i++) {
		while(x % i == 0) {
			cnt[i]++;
			x /= i;
			
			if (cnt[i] == 2)
				return false;
		}
	}
	
	return true;
}

int main() {
	long long n;
	cin >> n;
	
	vector<long long> factors = {n};
	
	for(long long i=2; i*i <= n; i++) {
		if (n % i == 0) {
			factors.push_back(i);
			factors.push_back(n/i);
		}
	}
	
	sort(factors.rbegin(), factors.rend());
	
	for(auto factor : factors) {
		if (is_valid(factor)) {
			cout << factor << endl;
			break;
		}
	}
}