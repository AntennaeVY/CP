#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	
	vector<int> a(n);
	for(auto &ai:a) cin >> ai;

	int l=-1, r=n+1;
	
	while(l+1 < r) {
		int mid = l+(r-l)/2;
	
		vector<int> a_sorted(a);
		sort(a_sorted.begin(), a_sorted.begin()+mid, greater<int>());
		
		long long sum = 0;
		
		for(int i=0; i < mid; i+=2) {
			sum += a_sorted[i];
		}
		
		if (sum <= h) 
			l = mid;
		else 
			r = mid;
	}
	
	cout << l << endl;
}