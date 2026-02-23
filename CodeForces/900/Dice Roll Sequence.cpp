#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	map<int, set<int>> m = {
		{1, {2,3,4,5}},
		{2, {1,3,4,6}},
		{3, {1,2,5,6}},
		{4, {1,2,5,6}},
		{5, {1,3,4,6}},
		{6, {2,3,4,5}}
	};
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int count = 1, ans = 0;
		for(int i=1; i < n; i++) {
			if (m[a[i]].count(a[i-1]))
				ans += count / 2, count = 1;
			else
				count += 1;
		}
		
		ans += count / 2;
		
		cout << ans << "\n";
	}
	
}