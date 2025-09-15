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
		
		vector<int> b = {a[0]};
		vector<vector<int>> v = {{a[0]}};
		
		for(int i=1; i < n; i++)
			if (a[i] != b.back())
				b.push_back(a[i]);
				
		for(int i=1; i < b.size(); i++)
			if (b[i-1] + 1 < b[i])
				v.push_back({b[i]});
			else
				v.back().push_back(b[i]);
		
		int ans = 0;
		for(int i=0; i < v.size(); i++)
			ans += (v[i].size() + 1)/2;
			
		cout << ans << endl;
	}
	
}