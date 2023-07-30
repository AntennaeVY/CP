#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		if (n == m) {
			cout << "YES" << endl;
			continue;
		}
		
		if (n % 3 != 0) {
			cout << "NO" << endl;
			continue; 
		}
		
		bool ok = false;
		
		priority_queue<int> q;
	
		if ((2*n)/3 >= m)
			q.push(2*n / 3);
			
		if (n/3 >= m)
			q.push(n/3);
		
		while(!q.empty()) {
			int x = q.top();
			q.pop();
			
			if (x == m) {
				ok = true;
				break;
			}
			
			if (x % 3 != 0 || (2*x)/3 < m)
				continue;
				
			if (x / 3 >= m)
				q.push(x / 3);
				
			q.push(2*x/3);
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}