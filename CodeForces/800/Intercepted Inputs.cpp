#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int k;
		cin >> k;
		
		vector<int> a(k);
		for(auto &ai : a) cin >> ai;
	
		map<int, int> mp;
	
		for(int i=0; i < k; i++) {
			mp[a[i]]++;
		}
		
		int x = k - 2;
		int n, m;
		
		for(int i=1; i*i <= x; i++) {
			if (x % i)
				continue;
				
			if (i*i == x) {
				if (mp[i] >= 2)
					n = i, m = i;
			} else if (mp[i] && mp[x/i]) {
				n = i, m = x/i;
			}
		}
		
		cout << n << " " << m << endl;
	}
}