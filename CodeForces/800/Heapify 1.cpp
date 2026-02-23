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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		if (n == 1){
			cout << "YES" << "\n";
			continue;
		}
		
		// 1, 2, 4, 8, 16, 32
		// 3, 6, 12, 24, 48
		// 5, 10, 
		
		for(int i=1; i <= n/2; i++) {
			if (i % 2 == 0)
				continue;
				
			vector<int> v;	
			for(int j=i; j <= n; j *= 2) {
				v.push_back(a[j-1]);
			}
			
			int k=0;
			sort(v.begin(), v.end());
		
			for(int j=i; j <= n; j *= 2, k++) {
				a[j-1] = v[k];
			}
		}
		
		// for(auto &ai : a)
			// cout << ai << " ";
		// cout << endl;
		
		bool ok = true;
		for(int i=1; i < n; i++) {
			ok &= a[i] > a[i-1];
		}
			
		cout << (ok ? "YES" : "NO") << '\n';
	}
}