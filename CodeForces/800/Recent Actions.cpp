#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> p(m);
		for(auto &pi : p) cin >> pi;
		
		deque<int> a(n);
		
		for(int i=n; i >= 1; i--) {
			a[n-i] = i;
		}
		
		vector<int> ans(n+1, -1);
		
		for(int i=0; i < m; i++) {
			auto it = find(a.begin(), a.end(), p[i]);
			
			if (it != a.end()) {
				a.erase(it);
				a.push_back(p[i]);
			} else {
				if (a[0] <= n)
					ans[a[0]] = i+1;
					
				a.pop_front();
				a.push_back(p[i]);
			}
		}
		
		for(int i=1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}