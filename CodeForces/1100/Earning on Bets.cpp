#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
		
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> k(n);
		for(auto &ki : k) cin >> ki;
		
		int sum = 0, d = 1;
		
		for(int i=0; i < n; i++)  {
			d = lcm(d, k[i]);
		}
		
		for(int i=0; i < n; i++) {
			sum += d / k[i];
		}
		
		if (sum >= d) {
			cout << -1 << endl;
			continue;
		} 
		
		for(int i=0; i < n; i++) {
			cout << d / k[i] << " ";
		}
		
		cout << endl;
		
	}
}