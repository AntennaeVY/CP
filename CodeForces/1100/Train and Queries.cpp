#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		map<int, pair<int,int>> m;

		for(int i{}; i < n; i++) {
			int x;
			cin >> x;
			
			if (!m.count(x)) {
				m[x].first = i;
				m[x].second = i;
			} else {
				m[x].second = i;
			}
		}
		
		for(int i{}; i < k; i++) {
			int aj, bj;
			cin >> aj >> bj;
			
			if (!m.count(aj) || !m.count(bj) || m[aj].first > m[bj].second) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
			}
		}
	}
}