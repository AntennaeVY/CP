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
		
		vector<int> b(n);
		for(int i=0; i < n; i++) {
			cin >> b[i];
		}
		
		auto f = [&](pair<int,int> p1, pair<int,int> p2, pair<int,int> p3){
			int d12 = abs(p1.first - p2.first) + abs(p1.second - p2.second);
			int d13 = abs(p1.first - p3.first) + abs(p1.second - p3.second);
			int d23 = abs(p2.first - p3.first) + abs(p2.second - p3.second);
			
			if (d12 + d13 == d23 || d12 + d23 == d13 || d23 + d13 == d12)
				return true;
				
			return false;
		};
		
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			for(int j=i; j < i+4 && j < n; j++) {
				bool ok = true;
				
				for(int x=i; x <= j; x++) {
					for(int y=x+1; y <= j; y++) {
						for (int z=y+1; z <= j; z++) {
							
							if (f({b[x], x}, {b[y], y}, {b[z], z}))
								ok = false;
							
							
						}
					}
				}
				
				if (ok)
					ans++;
			}
		}
		
		cout << ans << "\n";
	}
}