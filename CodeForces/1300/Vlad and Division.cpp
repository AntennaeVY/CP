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
		
		map<int, int> m;
		for(int i=0; i < n; i++) {
			m[a[i]]++;
		}
		
		int cnt = 0;
		int mask = (1LL << 31) - 1;
		
		for(int i=0; i < n; i++) {
			if (m[a[i]] > 0)
				cnt++;
			else
				continue;
				
			m[a[i]]--;
			m[a[i] ^ mask]--;
		}
		
		cout << cnt << endl;
	}
}