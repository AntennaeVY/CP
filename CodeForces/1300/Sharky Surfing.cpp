#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, L;
		cin >> n >> m >> L;
		
		vector<int> l(n), r(n);
		
		for(int i=0; i < n; i++) {
			cin >> l[i] >> r[i];
		}
		
		vector<pair<int,int>> p;
		
		for(int i=0; i < m; i++) {
			int xi, vi;
			cin >> xi >> vi;
			
			p.push_back({xi, vi});
		}
		
		priority_queue<int> pq;
		
		int jump = 1, ans = 0;
		int i = 1, k = 0;
		bool can = true;
		
		for(int j=0; j < n; j++) {
			i = l[j] - 1;
			
			for(; k < m; k++) {
				if (p[k].first <= i)
					pq.push(p[k].second);
				else
					break;
			}
			
			int dist = r[j] - l[j] + 1;
			
			while(!pq.empty() && jump <= dist) {
				jump += pq.top();
				ans++;
				
				pq.pop();
			}
			
			if (jump <= dist) {
				can = false;
				break;
			}
		}
		
		if (!can)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
}