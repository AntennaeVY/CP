#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		string s;
		cin >> s;
		
		vector<long long> p(n+1);
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
		
		stack<pair<int,int>> st;
		
		int l=0, r=n-1;
		
		while(l < r) {
			while(l < r && s[l] == 'R')
				l++;
			
			while(l < r && s[r] == 'L')
				r--;
				
			if (l < r)
				st.push({l, r});
				
			l++, r--;
		}
		
		long long ans = 0;
		
		while(!st.empty()) {
			auto [i, j] = st.top();
			
			ans += p[j+1] - p[i];
			
			st.pop();
		}
		
		cout << ans << endl;
	}
}