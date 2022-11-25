#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai:a) cin >> ai;
	
	long long ans = LLONG_MAX;
	
	for(int i=0; i < n; i++) {
		long long value = 0, current = 0;
		
		for(int j=i-1; j >= 0; j--) {
			value = a[j]*((value - a[j])/a[j]);
			current -= value/a[j];
		}

		value = 0;
		
		for(int j=i+1; j < n; j++) {
			value = a[j]*((value + a[j])/a[j]);
			current += value/a[j];
		}
		
		ans = min(ans, 1LL*current);
	}
	
	cout << ans << endl;
}