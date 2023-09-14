#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		
		if (n == 1) {
			cout << "YES" << endl;
		
			cout << s[0];
			for(int i=0; i < 26; i++) {
				if ('a'+i != s[0])
					cout << char('a'+i);
			}
			cout << endl;
			continue;
		}
		
		vector<bool> used(26);
		map<char, set<char>> graph;
		
		for(int i=1; i < n; i++) {
			graph[s[i]].insert(s[i-1]);
			graph[s[i-1]].insert(s[i]);
		}
		
		function<void(char, string&)> dfs;
		dfs = [&](char x, string &ans){
			if (used[x - 'a'])
				return;
				
			used[x - 'a'] = true;
			ans += x;
			
			for(char y : graph[x])
				dfs(y, ans);
		};
		
		string ans = "";
		bool ok = false, bad = false;
		
		for(int i=0; i < 26; i++) {
			if (graph['a'+i].size() > 2)
				bad = true;
			
			if (graph['a'+i].size() != 1)
				continue;
			
				dfs('a'+i, ans);
				ok = true;
		}
		
		if (!ok || bad) {
			cout << "NO" << endl;
			continue;
		}
		
		for(int i=0; i < 26; i++) {
			if (used[i])
				continue;
				
			ans += 'a'+i;
		}
		
		cout << "YES" << endl;
		cout << ans << endl;
	}
}