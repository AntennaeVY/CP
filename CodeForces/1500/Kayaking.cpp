#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	n *= 2;
	
	vector<int> w(n);
	for(auto &wi : w) cin >> wi;
	
	sort(w.begin(), w.end());
	
	int ans = 1e9;
	
	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			int cur = 0;
			vector<int> a;
			
			for(int k=0; k < n; k++) {
				if (k == i || k == j)
					continue;
					
				a.push_back(w[k]);
			}
			
			for(int i=1; i < n-2; i += 2) {
				cur += a[i] - a[i-1];
			}
			
			ans = min(ans, cur);
		}
	}
	
	cout << ans << endl;
}