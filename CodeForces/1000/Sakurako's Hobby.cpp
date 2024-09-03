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
		
		int k = 0;
		vector<int> c(n+1, -1);
		vector<int> ans(n+1, 0);
		
		map<int, vector<int>> m;
		vector<bool> vis(n+1);
		
		for(int i=0; i < n; i++) {
			int j = i;
			
			while(!vis[a[j]]) {
				vis[a[j]] = true;
				c[a[j]] = k;
				
				ans[k] += (s[j] == '0');
				
				j = a[j]-1;
			}
			
			k++;
		}
		
		for(int i=0; i < n; i++) {
			cout << ans[c[a[i]]] << " ";
		}
		
		cout << endl;
	}
}