#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, k;
	cin >> n >> k;
	
	vector<long long> p(n);
	for(auto &pi : p) cin >> pi;
	
	long long l = 0, r = *max_element(p.begin(), p.end());
	while(l+1 < r) {
		long long m = l + (r-l)/2;
		long long c = 0;
		
		for(int i=0; i < n; i++) {
			c += (p[i] + m - 1) / m;
		}
		
		if (c <= k)
			r = m;
		else
			l = m;
	}
	
	cout << r << endl;

}