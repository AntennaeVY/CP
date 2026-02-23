#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long n, k;
		cin >> n >> k;
		
		if (k == n) {
			cout << "0\n";
			continue;
		}
		
		map<int, int> m;
		queue<int> q;
		
		q.push(n);
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			
			int a = (x + 1) / 2;
			int b = x / 2;
			
			if (m.find(a) == m.end()) {
				m[a] = m[x] + 1;
				q.push(a);
			}
			
			if (m.find(b) == m.end()) {
				m[b] = m[x] + 1;
				q.push(b);
			}
		}
		
		cout << (m[k] ? m[k] : -1) << "\n";
	}
}