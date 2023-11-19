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
		
		map<int,int> cnt;
		
		for(int i=0; i < n; i++) {
			int x = a[i];
			
			while(x % 2 == 0) {
				x /= 2; 
				cnt[2]++;
			}
			
			for(int j=3; j*j <= a[i]; j+=2) {
				while (x % j == 0) {
					x /= j;
					cnt[j]++;
				}
			}
			
			cnt[x]++;
		}
		
		bool ok = true;
		
		for(auto &[x, y] : cnt) {
			if (x == 1)
				continue;
			
			ok &= (y % n == 0);
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}