#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		priority_queue<int, vector<int>, greater<int>> pq;
		vector<int> a(n), b(m);
		for(auto &ai:a) {
			cin >> ai;
			pq.push(ai);
		}
		
		for(auto &bi:b) cin >> bi;
		
		long long sum = 0;
		
		for(int i=0; i < m; i++) {
			pq.pop();
			pq.push(b[i]);
		}
		
		while(!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
		
		cout << sum << endl;
	}
}