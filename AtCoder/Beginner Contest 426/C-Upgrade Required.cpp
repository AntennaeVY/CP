#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> v(n+1);
	for(int i=1; i <= n; i++) {
		v[i] = 1;
	}
	
	int p = 1;
	
	while(q--) {
		int x, y;
		cin >> x >> y;
		
		int cnt = 0;
		
		while(p <= x) {
			cnt += v[p];
			v[p] = 0;
			
			p++;
		}
		
		v[y] += cnt;
			
		cout << cnt << "\n";
	}
}