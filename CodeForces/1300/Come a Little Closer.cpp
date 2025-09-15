#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> x(n), y(n);
		multiset<int> mx, my;
		
		for(int i=0; i < n; i++) {
			cin >> x[i] >> y[i];
			
			mx.insert(x[i]);
			my.insert(y[i]);
		}
		
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		
		long long ans = 2e18;
		
		for(int i=0; i < n; i++) {
			mx.erase(mx.find(x[i]));
			my.erase(my.find(y[i]));
			
			long long dx = *(prev(mx.end())) - *mx.begin() + 1;
			long long dy = *(prev(my.end())) - *my.begin() + 1;
			
			long long curr = dx * dy;
			
			if (curr == n-1)
				curr = curr + min(dx, dy);
				
			ans = min(ans, curr);
			
			mx.insert(x[i]);
			my.insert(y[i]);
		}
		
		cout << ans << "\n";
	}
}