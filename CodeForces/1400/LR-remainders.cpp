#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		string s;
		cin >> s;
		
		int l=0, r=n-1;
		for(int i=0; i < n-1; i++) {
			if (s[i] == 'L')
				l++;
			else
				r--;
		}
		
		long long ans = a[l] % m;
		vector<int> v;
		
		v.push_back(ans);
		
		for(int i=n-2; i >= 0; i--) {
			if (s[i] == 'L')
				ans *= a[--l];
			else
				ans *= a[++r];
				
			ans %= m;
			
			v.push_back(ans);
		}
		
		reverse(v.begin(), v.end());
		
		for(auto &vi : v) cout << vi << " ";
		
		cout << endl;
	}
}