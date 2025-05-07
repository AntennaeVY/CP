#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<long long> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<long long> d1(n-1), d2(n-1);
	
	for(int i=0; i < n-1; i++) {
		d1[i] = abs(a[i] - a[i+1]) * (i % 2 == 0 ? 1 : -1);
		d2[i] = abs(a[i] - a[i+1]) * (i % 2 == 1 ? 1 : -1);
	}
	
	long long sum = 0, ans = 0;
	
	for(int i=0; i < n-1; i++) {
		sum = max(d1[i], sum + d1[i]);
		ans = max(ans, sum);
	}
	
	sum = 0;
	 	
	for(int i=0; i < n-1; i++) {
		sum = max(d2[i], sum + d2[i]);
		ans = max(ans, sum);
	}
	
	cout << ans << endl;
}