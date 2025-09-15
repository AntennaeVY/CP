#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		long long m;
		cin >> n >> m;
		
		vector<set<int>> a(n);
		
		for(int i=0; i < n; i++) {
			int l;
			cin >> l;
			
			for(int j=0; j < l; j++) {
				int x;
				cin >> x;
				
				a[i].insert(x);
			}
		}
		
		set<int> achievable;
		
		for(int i=0; i < n; i++) {
			int l = a[i].size();
			int j = 0;
			int m1 = -1, m2 = -1;
			
			auto it = a[i].begin();
			
			while(it != a[i].end() && (m1 == -1 || m2 == -1)) {
				if (*it != j) {
					if (m1 == -1)
						m1 = j;
					else if (m2 == -1)
						m2 = j;
				} else {
					it++;
				}
				
				j++;
			}
			
			if (m1 == -1)
				m1 = *(prev(a[i].end())) + 1, m2 = m1 + 1;
			
			if (m2 == -1)
				m2 = *(prev(a[i].end())) + 1;
			
			achievable.insert(m1);
			achievable.insert(m2);
		}
		long long highest = (*prev(achievable.end()));
		long long ans = 0;
		
		if (highest >= m)
			ans = highest * (m+1);
		else
			ans = highest * (highest + 1) / 2 + m * (m+1) / 2;
		
		cout << ans << "\n";
	}
	
}