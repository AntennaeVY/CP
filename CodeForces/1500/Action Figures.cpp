#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long n;
		cin >> n;
		
		string s;
		cin >> s;
		
		long long ans = n*(n+1)/2;
		
		vector<bool> used(n);
		vector<int> ones, z;
		
		for(int i=n-1; i >= 0; i--)
			if (s[i] == '1')
				ones.push_back(i);
	
		for(int i=0; i < n; i++)
			if (s[i] == '0')
				z.push_back(i);
		
		for(int i=n-1; i >= 0; i--) {
			if (used[i] || s[i] == '0')
				continue;
				
			while(z.size() && z.back() > i)
				z.pop_back();
				
			if (z.size()) {
				ans -= i+1;
				z.pop_back();
			} else if (ones.back() != i) {
				ans -= i+1;
				
				used[ones.back()] = true;
				ones.pop_back();
			}
		}
		
		cout << ans << "\n";
	}
}