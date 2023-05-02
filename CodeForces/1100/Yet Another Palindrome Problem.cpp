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
		
		map<int, int> tot, cnt;
		
		for(int i=0; i < n; i++) {
			tot[a[i]]++;
		}
		
		bool ok = false;
		cnt[a[0]]++;
		
		for(int i=1; i < n; i++) {
			if (a[i] == a[i-1] && tot[a[i-1]] - cnt[a[i-1]] > 1 ||
				a[i] != a[i-1] && tot[a[i-1]] - cnt[a[i-1]] >= 1)
					ok = true;
					
				cnt[a[i]]++;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}		
}