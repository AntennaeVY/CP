#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	vector<pair<int,int>> a(n);
	vector<int> size(n), ans(n), b(n);
	
	for(int i=0; i < n; i++) {
		int enter, leave, c;
		cin >> enter >> leave >> c;
		
		size[i] = c;
		
		a[i] = {enter, i};
		b[i] = leave;
	}
	
	sort(a.rbegin(), a.rend());
	
	multiset<pair<int,int>> ms;
	int current = 0, t = 0;
	
	while(!a.empty()) {
		int j = a.back().second;
		int enter = a.back().first;
		
		if (current + size[j] <= k) {
			t = max(t, enter);
			ans[j] = t;
			
			current += size[j];
			ms.insert({t + b[j], size[j]});
			
			a.pop_back();
		} else {
			int leave = ms.begin()->first;
			current -= ms.begin()->second;
			
			t = max(t, leave);
			
			ms.erase(ms.begin());
		}
	}
	
	for(auto &ansi : ans)
		cout << ansi << "\n";
}