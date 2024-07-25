#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int l=0, r=1e9;
	while(l+1 < r) {
		int mid = l + (r-l)/2;
		
		long long sum = 0;
		
		for(int i=0; i < n; i++) {
			sum += max(0, a[i] - mid);
		}
		
		if (sum >= m)
			l = mid;
		else
			r = mid;
	}
	
	cout << l << endl;
}