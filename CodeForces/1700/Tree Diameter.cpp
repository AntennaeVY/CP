#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 0;
		
		for(int i=0; i < 9; i++) {
			vector<int> a, b;
			
			for(int j=1; j <= n; j++) {
				if ((j >> i) & 1)
					a.push_back(j);
				else
					b.push_back(j);	
			}
			
			if (a.empty() || b.empty())
				break;
			
			cout << a.size() << " " << b.size() << " ";
			
			for(auto x : a)
				cout << x << " ";
			
			for(auto y : b)
				cout << y << " ";
			
			cout << endl;
				
			int r;
			cin >> r;
			
			ans = max(ans, r);
		}
		
		cout << -1 << " " << ans << endl;
	}
}