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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> cnt(n+5), ans(n+5);
		for(int i=0; i < n; i++)
			cnt[a[i]] += 1;
			
		int rep = 0;
		for(int i=0; i <= n; i++) {
			ans[cnt[i]] += 1;
			ans[(n-i) + 1] -= 1;
			
			rep += cnt[i] - 1;
			
			if (cnt[i] == 0)
				break;
		}
		
		for(int i=1; i <= n; i++)
			ans[i] += ans[i-1];
		
		for(int i=0; i < n; i++)
			cout << ans[i] << " ";
			
		cout << "1\n";
	}
}