#include<bits/stdc++.h>
using namespace std;

bool dfs(string &str, map<string, vector<string>> &graph, map<string, bool> &seen) {
	seen[str] = true;
	
	bool new_component = false;
	
	for (string s : graph[str]) {
		if (s == str)
			new_component = true;
		
		if (seen[s])
			continue;
			
		new_component = true;
		dfs(s, graph, seen);
	}
	
	return new_component;
}

int main() {
	int n;
	cin >> n;
	
	set<string> t;
	vector<string> p;
	
	map<string, vector<string>> graph;
	
	for(int i=0; i < n; i++) {
		string str, new_str = "";
		cin >> str;
		
		set<char> s;
		
		for (char c : str) {
			s.insert(c);
		}
		
		for (char c : s) {
			new_str += c;
		}
		
		if (!t.count(new_str))
			p.push_back(new_str);
		
		t.insert(new_str);
		
		for (char c : new_str) {
			string letter(1, c);
			
			graph[letter].push_back(new_str);
			graph[new_str].push_back(letter);
		}
	}
	
	int ans = 0;
	map<string, bool> seen;
	
	for(int i=0; i < 26; i++) {
		string letter(1, (char)(97+i));
		
		if (graph.find(letter) == graph.end() || seen[letter])
			continue;
		
		ans += dfs(letter, graph, seen);
	}	
	
	cout << ans << endl;
}