#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> l(n), r(n), real(n);
		for(int i=0; i < n; i++)
			cin >> l[i] >> r[i] >> real[i];
		
		vector<int> z(n);
		iota(z.begin(), z.end(), 0);
		sort(z.begin(), z.end(), [&](int i, int j){ return l[i] < l[j]; });
			
		auto cmp = [&](int i, int j){
			return real[i] < real[j];
		};
			
		priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); 
		
		int cur = k;
		for(int i=0; i < n; i++) {
			if (l[z[i]] > cur){
				while(pq.size() && (l[pq.top()] > cur || r[pq.top()] < cur))
					pq.pop();
				
				if (pq.size())
					cur = max(cur, real[pq.top()]);
				
			}		
			
			pq.push(z[i]);		
		}
		
		while(pq.size() && (l[pq.top()] > cur || r[pq.top()] < cur))
			pq.pop();
				
		if (pq.size())
			cur = max(cur, real[pq.top()]);
		
		cout << cur << "\n";
	}
}