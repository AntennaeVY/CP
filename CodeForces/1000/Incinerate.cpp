#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> h(n), p(n), m(n);
		for(auto &hi:h) cin >> hi;
		for(auto &pi:p) cin >> pi;
		
		for(int i=0; i < n; i++) {
			m[i] = i;
		}
		
		sort(m.begin(), m.end(), [&](const int i, const int j){
			return p[i] < p[j];
		});
		
		
		bool can = true;
		int dealt = k;
		
		int i=0;
		
		while(i < n) {
			if (h[m[i]] - dealt <= 0){
				i++;
				continue;
			}
			
			if (k - p[m[i]] <= 0){
				can = false;
				break;
			}
				
			k -= p[m[i]];
			dealt += k;
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}