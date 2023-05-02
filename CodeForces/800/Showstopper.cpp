#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		int mx_a = *max_element(a.begin(), a.end());
		int mx_b = *max_element(b.begin(), b.end());
		
		if (max(mx_a, mx_b) != a.back() && max(mx_a, mx_b) != b.back()) {
			cout << "NO" << endl;
			continue;
		}
		
		if (max(mx_a, mx_b) != a.back())
			swap(a.back(), b.back());
			
		bool ok = true;
		
		for(int i=0; i < n-1; i++) {		
			if (a[i] > a.back() && b[i] > a.back())
				ok = false;
			else if (a[i] > a.back())
				swap(a[i], b[i]);
				
			if (b[i] > b.back() && a[i] > b.back())
				ok = false;
			else if (b[i] > b.back())
				swap(b[i], a[i]);
				
			if (b[i] > b.back() || a[i] > a.back())
				ok = false;				
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}