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
		
		vector<int> p(n,0), s(n,0);
		p[0] = a[0], s[n-1] = a[n-1];
		
		set<int> st = {a[0], a[n-1]};
		
		for(int i=1; i < n; i++) {	
			p[i] = min(p[i-1], a[i]);
			st.insert(p[i]);
		}
		
		for(int i=n-2; i >= 0; i--) {		
			s[i] = max(s[i+1], a[i]);
			st.insert(s[i]);
		}
		
		for(int i=0; i < n; i++)
			cout << st.count(a[i]);
		cout << '\n';
	}
}