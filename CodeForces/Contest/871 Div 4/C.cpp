#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> m(n);
		map<string, int> M;
		
		for(int i=0; i < n; i++) {
			cin >> m[i];
			
			string s;
			cin >> s;
			
			if (M.find(s) == M.end())
				M[s] = 1e9;
			
			M[s] = min(M[s], m[i]);
		}
		
		int both = 1e9, a = 1e9, b = 1e9;
		
		if (M.find("11") != M.end())
			both = M["11"];
			
		if (M.find("10") != M.end())
			a = M["10"];
			
		if (M.find("01") != M.end())
			b = M["01"];	
			
		if (both == 1e9 && (a == 1e9 || b == 1e9)){
			cout << -1 << endl;
			continue;
		}
			
		cout << min(a + b, both) << endl;
	}
}