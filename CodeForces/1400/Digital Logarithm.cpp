#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai:a) cin >> ai;
		for(auto &bi:b) cin >> bi;
		
		priority_queue<int> p(a.begin(), a.end()), q(b.begin(), b.end());
		
		int ans = 0;
		
		while(!p.empty()) {
			int x = p.top(), y = q.top();
			
			if (x == y) {
				p.pop();
				q.pop();
			} else if (x > y) {
				p.pop();
				p.push(log10(x) + 1);
				ans++;
			} else {
				q.pop();
				q.push(log10(y) + 1);
				ans++;
			}
		}
		
		cout << ans << endl;
	}
}