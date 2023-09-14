#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, int> cnt;
		for(int i=0; i < n; i++)
			cnt[a[i]]++;
			
		vector<int> mx(n+1);
		mx[0] = n;
		
		for(int i=1; i <= n; i++) {
			mx[i] = mx[i-1] - cnt[i];
		}
		
		int idx = 0;
		bool ok = true;
		
		for(int i=0; i < n; i++, idx++) {
			if (mx[idx] != a[i])
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}