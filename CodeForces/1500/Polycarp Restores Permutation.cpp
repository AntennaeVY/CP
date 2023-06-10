#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> q(n-1);
	for(auto &qi : q) cin >> qi;
	
	vector<long long> p(n), pref(n, 0);
	
	long long mn = 0;
	for(int i=0; i < n-1; i++) {
		pref[i+1] = pref[i] + q[i];
		mn = min(mn, pref[i+1]);
	}
	
	p[0] = 1 - mn;

	for(int i=1; i < n; i++) {
		p[i] = pref[i]+p[0];
	}
	
	vector<long long> check = p;
	sort(check.begin(), check.end());
	
	bool ok = true;
	
	for(int i=0; i < n; i++) {
		if (check[i] != i+1)
			ok = false;
	}
	
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	
	for(int i=0; i < n; i++) {
		cout << p[i] << " \n"[i==n-1];
	}
}