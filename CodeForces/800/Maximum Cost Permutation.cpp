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
		
		vector<int> p(n);
		for(auto &pi : p) cin >> pi;
		
		set<int> s;
		for(int i=1; i <= n; i++) 
			s.insert(i);
		
		for(int i=0; i < n; i++)
			s.erase(p[i]);
		
		for(int i=n-1; i >= 0; i--) {
			if (p[i] == 0)
				p[i] = *s.begin();
				
			s.erase(p[i]);
		}
		
		int l=0, r=n-1;
		
		while(l < r && p[l] == l+1) {
			l++;
		}
			
		while(r > l && p[r] == r+1){
			r--;
		}
		
			
		if (l == r && p[l] == l+1) {
			cout << 0 << "\n";
		} else {
			cout << r-l+1 << "\n";
		}
	}
}