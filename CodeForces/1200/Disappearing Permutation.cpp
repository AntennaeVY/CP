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
		
		vector<int> p(n);
		for(auto &pi : p) {
			cin >> pi;
			pi--;
		}
		
		vector<int> d(n);
		for(auto &di : d) {
			cin >> di;
			di--;
		}
		
		vector<bool> seen(n, false);
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			int x = d[i];
			
			while(!seen[x]) {
				ans++;
				seen[x] = true;
				x = p[x];
			}
			
			cout << ans << " ";
		}
		
		cout << endl;
	}
}