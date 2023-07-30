#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n,x,y;
		cin >> n >> x >> y;
		
		string a, b;
		cin >> a >> b;
		
		int to_change = 0;
		
		for(int i=0; i < n; i++) {
			to_change += (a[i] != b[i]);
		}
		
		if (to_change % 2) {
			cout << -1 << endl;
			continue;
		}
		
		int adjacent = 0;
		set<int> adjacent_seen;
		
		for(int i=1; i < n; i++) {
			if (a[i] != b[i] && a[i-1] != b[i-1]){
				adjacent_seen.insert(i);
				adjacent_seen.insert(i-1);
			}
		}
		
		long long ans = 0;
		
		if (adjacent_seen.size() == 2 && to_change == 2) {
			ans = (x < 2*y ? x : 2*y);
		} else {
			ans = (to_change/2)*y;
		}
		
		cout << ans << endl;
	}
}