#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> p(n);
		for(auto &pi : p) cin >> pi;
		
		vector<int> ans;
		
		int r=0, mx=0;
		for(int i=0; i < n; i++) {
			if (i < n-1 && p[i+1] > mx)
				r = i, mx = p[i+1];
				
			if (i == n-1 && p[i] >= mx)
				r = i;
		} 
		
		for(int i=r+1; i < n; i++) {
			ans.push_back(p[i]);
		} 
		
		ans.push_back(p[r]);
		
		int l=r-1;
		for(int i=r-1; i >= 0; i--) {
			if (p[i] <= p[0])
				break;
				
			ans.push_back(p[i]);
			l--;
		}
		
		for(int i=0; i <= l; i++) {
			ans.push_back(p[i]);
		}
		
		for(auto &ansi : ans) 
			cout << ansi << " ";
			
		cout << endl;
	}
}