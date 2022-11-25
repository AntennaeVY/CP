#include<bits/stdc++.h>
using namespace std;

int binarySearch(int num, vector<int> &a) {
	int left = -1, right = a.size();
	
	while(left+1 < right) {
		int mid = left + (right-left)/2;
		
		if (a[mid] <= num) {
			left = mid;
		} else {
			right = mid;
		}
	}

	return left+1;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, l, r;
		cin >> n >> l >> r;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		long long ans = 0;
		sort(a.begin(), a.end());
		
		for(int i=0; i < n; i++) {
			if (a[i] >= r) continue;
			
			ans += binarySearch(r-a[i], a) - (a[i] <= r-a[i]);
			
			if (a[i] >= l-1) continue;
			
			ans -= binarySearch(l-1-a[i], a) - (a[i] <= l-1-a[i]);
		}
		
		cout << ans/2 << endl;
	}	
}