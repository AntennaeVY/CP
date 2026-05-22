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
		
		vector<int> six, two, three, rest;
		for(int i=0; i < n; i++) {
			if (a[i] % 6 == 0)
				six.push_back(a[i]);
			else if (a[i] % 2 == 0)
				two.push_back(a[i]);
			else if (a[i] % 3 == 0)
				three.push_back(a[i]);
			else
				rest.push_back(a[i]);
		}
		
		vector<int> ans(n);
		
		int l=0, r=n-1;
		for(int i=0; i < six.size(); i++) {
			if (i % 2 == 0)
				ans[l++] = six[i];
			else
				ans[r--] = six[i]; 
		}
		
		for(int i=0; i < two.size(); i++) {
			ans[l++] = two[i];
		}
		
		for(int i=0; i < three.size(); i++) {
			ans[r--] = three[i];
		}
		
		for(int i=0; i < rest.size(); i++) {
			ans[l++] = rest[i];
		}
		
		for(auto &ansi : ans)
			cout << ansi << " ";
		cout << "\n";
	}
}