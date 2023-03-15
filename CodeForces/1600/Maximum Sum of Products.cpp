#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<long long> a(n), b(n);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	vector<long long> p(n+1, 0);
	
	for(int i=0; i < n; i++) {
		p[i+1] = p[i] + a[i]*b[i];
	}
	
	long long ans = p[n];

	for(int i=0; i < n; i++) {
		long long curr = a[i]*b[i];
		
		for(int l=i-1, r=i+1; l >= 0 && r < n; l--, r++) {
			curr += a[l]*b[r] + a[r]*b[l];
			
			ans = max(ans, p[l] + curr + (p[n] - p[r+1]));
		}
		
		curr = 0;
		
		for(int l=i, r=i+1; l >= 0 && r < n; l--, r++) {
			curr += a[l]*b[r] + a[r]*b[l];
			
			ans = max(ans, p[l] + curr + (p[n] - p[r+1]));
		}
	}
	
	cout << ans << endl;
}