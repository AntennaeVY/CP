#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		map<int, int> cnt;
		vector<int> a(n*m), z(n*m);
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> a[i*m + j];
				
				z[i*m + j] = i*m + j;
				cnt[a[i*m + j]]++;		
			}
		}
		
		sort(z.begin(), z.end(), [&](const int &i, const int &j) {
			if (a[i] == a[j])
				return i < j;
			
			return a[i] < a[j];
		});
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				int current = a[z[i*m + j]];
				int end = min(j + cnt[current], m);
				
				cnt[current] -= end - j;
				
				sort(z.begin() + i*m + j, z.begin() + i*m + end, [&](const int &x, const int &y){
					return x > y;	
				});
				
				j = end - 1;
			}
		}
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			vector<int> s;
			
			for(int j=0; j < m; j++) {
				int x = z[i*m + j];
				s.push_back(x);
				
				sort(s.begin(), s.end());
				ans += lower_bound(s.begin(), s.end(), x) - s.begin();
			}
		}
		
		cout << ans << endl;	
	}
}