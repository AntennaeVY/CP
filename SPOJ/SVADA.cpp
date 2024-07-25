#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	int n;
	cin >> n;
	
	vector<int> a(n), b(n);
	for(int i=0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	
	int m;
	cin >> m;
	
	vector<int> c(m), d(m);
	for(int i=0; i < m; i++) {
		cin >> c[i] >> d[i];
	}
	
	int l = 0, r = t;
	while(l+1 < r) {
		int x = l + (r-l)/2;
		
		long long sum = 0;
		
		for(int i=0; i < n; i++) {
			if (x < a[i])
				continue;
				
			sum += 1 + (x - a[i]) / b[i];
		}
		
		long long cnt = 0;
		
		for(int i=0; i < m; i++) {
			if (t - x < c[i])
				continue;
				
			cnt += 1 + (t - x - c[i]) / d[i];
		}
		
		if (cnt >= sum)
			l = x;
		else
			r = x;
	}
	
	cout << l << endl;
}