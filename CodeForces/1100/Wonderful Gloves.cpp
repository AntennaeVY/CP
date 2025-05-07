#include<bits/stdc++.h>
using namespace std;

long long f(vector<int> &a, vector<int>&b, int k) {
	long long ans = accumulate(a.begin(), a.end(), 0LL);
			
	for(int i=0; i < b.size(); i++) {
		if (k == 0)
			break;
		
		ans += 1;
		
		if (i > 0)
			ans += b[i-1] - 1;
			
		k--;
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> l(n), r(n);
		for(auto &li : l) cin >> li;
		for(auto &ri : r) cin >> ri;
		
		for(int i=0; i < n; i++) {
			if (l[i] < r[i])
				swap(l[i], r[i]);
		}
		
		sort(l.rbegin(), l.rend());
		sort(r.rbegin(), r.rend());
		
		
		long long sl = accumulate(l.begin(), l.end(), 0LL);
		long long sr = accumulate(r.begin(), r.end(), 0LL);
	

		cout << f(l, r, k) << "\n";
	}
}