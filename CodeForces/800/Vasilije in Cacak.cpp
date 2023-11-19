#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n, k, x;
		cin >> n >> k >> x;
		
		long long min_sum = (k * (k+1))/2;
		
		if (min_sum > x) {
			cout << "NO" << endl;
			continue;
		}
		
		int mult = n - k;
		
		if (min_sum + k * mult < x) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
	}
}