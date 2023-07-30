#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
	
		vector<int> a(n);
		vector<long long> p(n+1);
		for(auto &ai : a) cin >> ai;
		
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
		
		int l=0, r = n;
		
		while(l + 1 < r) {
			int mid = l + (r-l)/2;
			
			cout << "? " << mid-l << " ";
			for(int i=l+1; i <= mid; i++) {
				cout << i << " ";
			}
			
			cout << endl;
			
			long long x;
			cin >> x;
			
			if (p[mid] - p[l] == x)
				l = mid;
			else
				r = mid;
		}
		
		cout << "! " << r << endl;
 	}
}