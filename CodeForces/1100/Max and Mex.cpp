#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		set<int> s;
		vector<int> a(n);
		
		int mex = n, mx = 0;
		
		for(int i{}; i < n; i++) {
			cin >> a[i];
			
			s.insert(a[i]);
			mx = max(a[i], mx);
		}
		
		for(int i{}; true; i++) {
			if (!s.count(i)) {
				mex = i;
				break;
			}
		}
		
		if (k==0) {
			cout << s.size() << endl;
			continue;
		}
		
		for(int i{}; i < k; i++) {
			int update = (mex+mx+1)/2;
			
			if (mex > mx) {
				cout << s.size()+k << endl;
				break;
			}
			
			if (update != mex) {
				s.insert(update);
				cout << s.size() << endl;
				break;
			}
			
			s.insert(update);
			
			for(int j=mex+1; true; j++) {
				if (!s.count(j)) {
					mex = j;
					break;
				}
			}
		}
	}
}