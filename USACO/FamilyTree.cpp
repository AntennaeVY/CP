#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("family.in", "r", stdin);
	freopen("family.out", "w", stdout);

	int n;
	cin >> n;
	
	string x, y;
	cin >> x >> y;
	
	map<string, vector<string>> g1, g2;
	for(int i=0; i < n; i++) {
		string u, v;
		cin >> u >> v;
		
		g1[u].push_back(v);
		g2[v].push_back(u);
	}
	
	bool cousins = true, unrelated = true;
	
	for(int i=0; i < 2; i++) {
		map<string, bool> related;
		
		auto check = [&](auto &&self, string u, string p = "") -> void {
			related[u] = true;
			
			for(auto &v : g1[u])
				if (v != p)
					self(self, v, u); 
			
			for(auto &v : g2[u])
				if (v != p)
					self(self, v, u);
		};
		
		check(check, x);
		
		if (related[x] != related[y]) {
			unrelated &= true;
			swap(x, y);
			
			continue;
		} else {
			unrelated &= false;
		}
		
		bool desc = false, sib = false;
		int d = 0;
		
		auto dfs = [&](auto &&self, string u, string p = "") -> void {
			if (u == y)
				desc = true;
			
			for (auto &v : g1[u]) {
				if (v == y && u != x)
					sib = true;
			}
					
			if (desc || sib)
				return;
			
			d++;
			
			for(auto &v : g2[u]) {
				self(self, v, u);
			}
		};
		
		dfs(dfs, x);
		
		if (!sib && !desc && related[x] == related[y]) {
			cousins &= true;
			swap(x, y);
			
			continue;
		} else {
			cousins &= false;
		}
		
		if (sib && d == 1) {
			cout << "SIBLINGS" << endl;
			return 0;
		}
		
		if (desc) {
			cout << y << " is the ";
			
			for(int i=3; i <= d; i++) {
				cout << "great-";
			}
			
			if(d >= 2)
				cout << "grand-";
			
			cout << "mother of " << x << endl;
			
			return 0;
		}
		
		if (sib) {
			cout << y << " is the ";
			
			for(int i=3; i <= d; i++) {
				cout << "great-";
			}
			
			cout << "aunt of " << x << endl;
			
			return 0;
		}
		
		swap(x, y);
	}
	
	if (!cousins && !unrelated)
		return 0;
	
	if (unrelated)
		cout << "NOT RELATED" << endl;
	else if (cousins)
		cout << "COUSINS" << endl;
}