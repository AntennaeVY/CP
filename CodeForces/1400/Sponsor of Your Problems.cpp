#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string l, r;
		cin >> l >> r;
		
		int n = l.size();
		
		int i = 0, ans = 0;
		for(i=0; i < n; i++) {
			if (l[i] != r[i])
				break;
				
			ans += 2;
		}
		
		
		if (i == n || r[i] - l[i] > 1) {
			cout << ans << "\n";
			continue;
		}
		
		int ans1 = ans+1, ans2 = ans+1;
		
		// chose first
		for(int j=i+1; j < n; j++) {
			if (r[j] == '0') {
				ans1 += 1 + (l[j] == '0');
				continue;
			}
			
			if (r[j] == '1') { 
				ans1 += (l[j] == '0');
			}
			
			break;
		}
		
		// chose second
		for(int j=i+1; j < n; j++) {
			if (l[j] == '9') {
				ans2 += 1 + (r[j] == '9');
				continue;
			}
			
			if (l[j] == '8') {
				ans2 += (r[j] == '9');
			}
			
			break;
		}
		
		cout << min(ans1, ans2) << "\n";
	}
}