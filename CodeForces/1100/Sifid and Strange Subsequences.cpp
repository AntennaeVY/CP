#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b;
		for(auto &ai:a) cin >> ai;
		
		for(int i=0; i < n; i++) {
			if (a[i] <= 0)
				b.push_back(a[i]);
		}
		
		int mn = INT_MAX;
		sort(b.begin(), b.end());
		
		for(int i=1; i < b.size(); i++) {
			mn = min(mn, abs(b[i] - b[i-1]));
		}
		
		for(int i=0; i < n; i++) {
			if (a[i] > 0 && a[i] <= mn) {
				b.push_back(a[i]);
				break;
			}
		}
		
		cout << max((int)b.size(), 1) << endl;
	}
}