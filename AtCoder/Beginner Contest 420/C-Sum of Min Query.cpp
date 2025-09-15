#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> a(n), b(n);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	long long sum = 0;
	vector<int> ans(n);
	
	for(int i=0; i < n; i++)
		ans[i] = min(a[i], b[i]), sum += ans[i];
	
	while(q--) {
		char c;
		cin >> c;
		
		int x, v;
		cin >> x >> v;
		
		x--;
		
		if (c == 'A') {
			sum -= ans[x];
			
			a[x] = v;
			ans[x] = min(a[x], b[x]);
			
			sum += ans[x];
		} else {
			sum -= ans[x];
			
			b[x] = v;
			ans[x] = min(b[x], a[x]);
			
			sum += ans[x];
		}
			
		cout << sum << "\n";
	}
}