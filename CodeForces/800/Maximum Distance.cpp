#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> x(n), y(n);
	for(auto &xi : x) cin >> xi;
	for(auto &yi : y) cin >> yi;
	
	int ans = 0;
	
	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			ans = max(ans, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		}
	}
	
	cout << ans << endl;
}