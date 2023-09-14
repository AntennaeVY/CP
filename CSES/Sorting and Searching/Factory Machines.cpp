#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end());
	
	long long l=0, r=1e18;
	while(l+1 < r) {
		long long x = l + (r-l)/2;
		
		unsigned long long cnt = 0;
		
		for(int i=0; i < n; i++) {
			cnt += x/a[i];
			
			if (cnt >= t)
				break;
		}
		
		if (cnt >= t)
			r = x;
		else
			l = x;
	}
	
	cout << r << endl;
}