#include<bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(7);
	
	long long n, k, m;
	cin >> n >> k >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.rbegin(), a.rend());
	
	vector<long long> ps(n+1, 0);
	
	for(int i=0; i < n; i++) {
		ps[i+1] = ps[i] + a[i];
	}
	
	vector<long double> ans(n, 0);
	
	for(int i=0; i < min(n, m+1); i++) {
		long long e = n-i;
		long long add = ps[e] + min(m-i, k * e);
		
		ans[i] = (long double)1.0 * add / e;
	}
	
	cout << *max_element(ans.begin(), ans.end()) << endl;
}