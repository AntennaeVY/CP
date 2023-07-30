#include<bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll, ll> decomposition(ll n) {
	pair<ll,ll> ans = {n, 1};
	
	ll divisor = 2;
	
	while(n > 1 && divisor * divisor <= n) {
		int count = 0;
		
		while(n%divisor == 0) {
			count++;
			n /= divisor;
		}
		
		if (count > ans.second) {
			ans.first = divisor;
			ans.second = count;
		}
		
		divisor++;
	}
	
	return ans;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		ll n;
		cin >> n;
		
		pair<ll,ll> maxDivisor = decomposition(n);
		
		cout << maxDivisor.second << endl;
		
		if (maxDivisor.second == 1) {
			cout << maxDivisor.first << endl;
			continue;
		}
		
		for(int i=1; i < maxDivisor.second; i++) {
			cout << maxDivisor.first << " ";
			n /= maxDivisor.first;
		}
		
		cout << n << endl;
	}
}