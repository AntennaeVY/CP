#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		map<int, int> f;
		priority_queue<int> p;
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			
			f[a[i]]++;
		}
		
		for(auto [first, second] : f) {
			p.push(second);
		}
		
		while(p.size() >= 2) {
			int x = p.top();
			p.pop();
			int y = p.top();
			p.pop();
			
			if (x == 1)
				continue;
				
			if (y == 1) {
				p.push(x-1);
			} else {
				p.push(x-1);
				p.push(y-1);
			}
		}
		
		int ans = 0;
		
		if (!p.empty()) {
			ans += p.top();
		}
		
		cout << ans << endl;
	}
}