#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
	
		vector<int> ans1, ans2, ans3;
		
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < n-1; j++) {
				if(a[j] > a[j+1]) {
					swap(a[j], a[j+1]);
					ans1.push_back(j+1);
				}
			}
		}
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < n-1; j++) {
				if(b[j] > b[j+1]) {
					swap(b[j], b[j+1]);
					ans2.push_back(j+1);
				}
			}
		}
	
		for(int i=0; i < n; i++) {
			if (a[i] < b[i])
				continue;
				
			swap(a[i], b[i]);
			ans3.push_back(i+1);
		}
		
		int k = ans1.size() + ans2.size() + ans3.size();
		
		assert(k < 1709);
		
		cout << k << "\n";
		
		for(auto i : ans1) {
			cout << "1 " << i << "\n";
		}
		
		for(auto i : ans2) {
			cout << "2 " << i << "\n";
		}
		
		for(auto i : ans3) {
			cout << "3 " << i << "\n";
		}
		
		
		for(int i=0; i < n; i++) {
			assert(a[i] < b[i]);
		}
		
		for(int i=1; i < n; i++) {
			assert(a[i] > a[i-1]);
			assert(b[i] > b[i-1]);
		}
		
		// dbg
		// for(int i=0; i < n; i++) {
			// cout << a[i] << " ";
		// }
		// cout << endl;
// 		
		// for(int i=0; i < n; i++) {
			// cout << b[i] << " ";
		// }
		// cout << endl;
		// cout << "=================\n";
	}
}