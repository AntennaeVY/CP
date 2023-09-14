#include<bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(10);
	
	int n;
	cin >> n;
	
	vector<int> x(n), v(n);
	for(auto &xi : x) cin >> xi;
	for(auto &vi : v) cin >> vi;
	
	long double l=0, r=1e9;
	
	while(r-l > 1e-7) {
		long double t = l + (r-l)/2;
		
		long double maxL = 0, minR = 1e18;
		for(int i=0; i < n; i++) {
			maxL = max(maxL, x[i] - t*v[i]);
			minR = min(minR, x[i] + t*v[i]);
		}
		
		if (maxL <= minR)
			r = t;
		else
			l = t;
	} 
	
	cout << r << endl;
}