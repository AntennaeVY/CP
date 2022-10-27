#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		long long sum = 0;
		map<int, int> m;
		map<int, bool> visited;
		set<int> s;
		
		vector<int> a(n);
		
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			
			m[a[i]]++;
			s.insert(a[i]);
		}
		
		long long ans = 0;
		
		if (2*sum % n != 0) {
			cout << 0 << endl;
			continue;
		}
		
		long long target = 2*sum/n;
		
		for (auto x : s) {
			if (s.count(target-x) && !visited[x] && !visited[target-x]) {
				
				if (target != 2*x)
					ans += 1LL*m[x]*m[target-x];
				else
					ans += 1LL*m[x]*(m[x]-1)/2;
				
				visited[x] = true;
				visited[target-x] = true;
			}
		}
		
		cout << ans << endl;
	}
}