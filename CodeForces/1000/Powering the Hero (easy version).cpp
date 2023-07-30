#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> s(n);
		for(auto &si : s) cin >> si;
		
		long long ans = 0;
		priority_queue<int> pq;
	
		pq.push(0);
		
		for(int i=0; i < n; i++) {
			if (s[i] == 0) {
				ans += pq.top();
				pq.pop();
			}
			
			pq.push(s[i]);
		}
		
		cout << ans << endl;
	}
}