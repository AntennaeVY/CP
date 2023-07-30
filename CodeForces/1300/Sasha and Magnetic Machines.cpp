#include<bits/stdc++.h>
using namespace std;

vector<int> get_divisors_until_root(int n) {
	vector<int> divisors;
	
	for(int i=2; i*i <= n; i++) {
		if (n % i == 0)
			divisors.push_back(i);
	}
	
	return divisors;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai:a) cin >> ai;
	
	long long sum = 0;
	int mn = 1e9;
	
	for(int i=0; i < n; i++) {
		sum += a[i];
		mn = min(mn, a[i]);
	}
	
	long long ans = sum;
	
	for(int i=0; i < n; i++) {
		if (a[i] == mn) 
			continue;
		
		auto div = get_divisors_until_root(a[i]);
		
		for(auto d : div) {
			ans = min(ans, sum - (a[i]+mn) + (a[i]/d + mn*d));
		}
	}	
	
	cout << ans << endl;
}