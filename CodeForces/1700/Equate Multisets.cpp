#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> b(n);
		for(auto &bi : b) cin >> bi;
		
		multiset<int> ms;
		
		for(int i=0; i < n; i++) {
			while((a[i] & 1) == 0)
				a[i] = (a[i] >> 1);
			
			ms.insert(a[i]);
			
			while((b[i] & 1) == 0)
				b[i] = (b[i] >> 1);
		}
		
		sort(b.rbegin(), b.rend());

		bool ok = true;
		
		for(int i=0; i < n; i++) {
			bool op = false;
			
			while(b[i] > 0) {
				auto it = ms.find(b[i]);
				
				if (it != ms.end()) {
					op = true;
					ms.erase(it);
					break;
				}
				
				b[i] >>= 1;
			}
		
			ok &= op;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}