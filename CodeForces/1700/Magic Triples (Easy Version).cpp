#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<long long, long long> m;
		for(int i=0; i < n; i++) {
			m[a[i]]++;
		}
		
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		n = a.size();
		
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			if (m[a[i]] >= 3) 
				ans += m[a[i]] * (m[a[i]] - 1) * (m[a[i]] - 2);
				
			if (a[i] != 1 && m.find(a[i]*a[i]) != m.end())
				ans += m[1] * m[a[i]] * m[a[i]*a[i]];
			
			for(int j=2; j*j <= a[i]; j++) {
				if (a[i] % j)
					continue;
					
				if (m.find(a[i] / j) != m.end() && m.find(a[i] * j) != m.end())
					ans += m[a[i] / j] * m[a[i]] * m[a[i] * j];
				
				if (j * j == a[i])
					continue;
					
				long long d = (a[i] / j);
			
				if (m.find(a[i] / d) != m.end() && m.find(a[i] * d) != m.end())
					ans += m[a[i] / d] * m[a[i]] * m[a[i] * d];
			}
		}
		
		cout << ans << endl;
	}
}