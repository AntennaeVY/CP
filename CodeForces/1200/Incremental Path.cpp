#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		string s;
		cin >> s;
		
		set<int> st;
		for(int i=0; i < m; i++) {
			int k;
			cin >> k;
			
			st.insert(k);
		}
		
		int x = 1;
		for(int i=0; i < n; i++) {
			if (s[i] == 'A') {
				x++;
			} else {
				while(st.count(x+1))
					x++;
					
				x++;
			}
			
			st.insert(x);
			
			if (s[i] == 'B') {
				while(st.count(x+1))
					x++;
					
				x++;
			}
		}
		
		cout << st.size() << "\n";
		
		for(auto &si : st)
			cout << si << " ";
		cout << "\n";
	}
}