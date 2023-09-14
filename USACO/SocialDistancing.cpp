#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	
	long long n, m;
	cin >> n >> m;
	
	vector<long long> L(m), R(m);
	for(int i=0; i < m; i++) {
		cin >> L[i] >> R[i];
	}
	
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	
	long long l=0, r=1e18;
	while(l+1 < r) {
		long long d = l + (r-l)/2;
		
		long long cnt = 1, last = L[0];
		
		for(int i=0; i < m; i++) {
			if (last + d <= L[i]) 
				last = L[i], cnt++;
				
			while(last + d <= R[i]) {
				cnt++, last += d;
			}
		}
		
		if (cnt >= n)
			l = d;
		else
			r = d;
	}
	
	cout << l << endl;
	
}