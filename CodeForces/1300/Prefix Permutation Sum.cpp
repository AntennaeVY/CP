#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n, 0);
		for(int i=1; i < n; i++) {
			cin >> a[i];
		}
		
		map<long long, int> m;
		vector<long long> b;
		
		bool ok = true;
		
		for(int i=1; i < n; i++) {
			b.push_back(a[i] - a[i-1]);
			m[b.back()]++;
			
			if (b.back() > n + n-1)
				ok = false;
		} 
		
		int cnt = 0, sum = 0;
		for(int i=1; i <= n; i++) {
			if (m[i] == 0)
				cnt++, sum += i;
		}
		
		if (cnt == 1 && ok) {
			cout << "YES" << endl;
			continue;
		}
		
		if (cnt > 2)
			ok = false;
			
		if (sum > n && m[sum] == 0 || sum <= n && m[sum] < 2)
			ok = false;
			
		cout << (ok ? "YES" : "NO") << endl;
	}
}