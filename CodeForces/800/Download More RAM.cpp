#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<pair<int,int>> q(n);
		for(int i=0; i < n; i++) {
			cin >> q[i].first;
		}
		
		for(int i=0; i < n; i++) {
			cin >> q[i].second;
		}
		
		sort(q.begin(), q.end());
		
		int cnt = k;
		
		for(int i=0; i < n; i++) {
			if (q[i].first <= cnt)
				cnt += q[i].second;
		}
		
		cout << cnt << endl;
	}
}