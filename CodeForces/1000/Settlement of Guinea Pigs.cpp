#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 0, free = 0, cnt = 0;
		
		for(int i=0; i < n; i++) {
			int c;
			cin >> c;
			
			if (c == 1) {
				cnt++;
			} else if (c == 2) {
				free += cnt;
				cnt = 0;
			}
			
			ans = max(ans, cnt + (free != 0 ? free/2 + 1 : 0));
		}
		
		cout << ans << endl;
	}
}