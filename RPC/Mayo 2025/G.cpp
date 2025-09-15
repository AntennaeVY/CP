#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000+5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string a, b;
		cin >> a >> b;
		
		int n = a.size(), ans = 0;
		
		
		for(int L=1; L <= n; L++) {
			map<vector<int>, int> m;
			vector<int> cnt(26, 0);
			
			for(int i=0; i < L; i++)
				cnt[b[i] - 'a']++;
				
			m[cnt]++;
				
			for(int i=1; i+L <= n; i++) {
				cnt[b[i-1] - 'a']--;
				cnt[b[i+L-1] - 'a']++;
				m[cnt]++;
			}
			
			cnt.assign(26, 0);
			
			for(int i=0; i < L; i++)
				cnt[a[i] - 'a']++;
				
			ans += m[cnt];
				
			for(int i=1; i+L <= n; i++) {
				cnt[a[i-1] - 'a']--;
				cnt[a[i+L-1] - 'a']++;
				ans += m[cnt];
			}
		}
	
		
		cout << ans << "\n";
	}
}