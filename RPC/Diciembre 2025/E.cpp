#include<bits/stdc++.h>
using namespace std;

const int K = 26;
const int MAXN = 1e6 + 5;
long long st[K + 1][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> d(n);
	for(auto &di : d) cin >> di;
	
	vector<int> e(n);
	for(auto &ei : e) cin >> ei;
	
	std::copy(d.begin(), d.end(), st[0]);
	
	for (int i = 1; i <= K; i++)
	    for (int j = 0; j + (1 << i) <= n; j++)
	        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	        
	vector<int> ans;
	        
	for(int i=n-1; i >= 0; i--) {
		int l = i, r = n;
		while(l+1 < r) {
			int m = l + (r-l)/2;
			
			int lg = __lg(m-l);
			int mn = min(st[lg][l+1], st[lg][m - (1 << lg) + 1]);
			
			// cout << i << " [" << l+1 << "," << m << "] " << mn << endl;
			// cout << lg << " " << l+1 << " " << m - (1 << lg) + 1 << endl;
			
			if (mn < d[i])
				r = m;
			else
				l = m;
		}
		
		
		if (r == n || e[r] < e[i]) {
			ans.push_back(i);
		} 
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	
	for(int i=0; i < ans.size(); i++)
		cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
}