#include<bits/stdc++.h>
using namespace std;

class DSU {
	private:
		vector<int> parent;
		vector<int> size;
		vector<int> mx;
		vector<string> names;
		
	public:
		DSU(int n, vector<int> &t, vector<string> &s) {
			parent.assign(n+5, -1);
			size.assign(n+5, 1);
			mx.assign(n+5, -1);
			names.assign(n+5, "");
			
			for(int i=0; i < n; i++) {
				mx[i] = t[i];
				names[i] = s[i];
			}
		}
		
		int find(int x) {
			if (parent[x] == -1)
				return x;
				
			return parent[x] = find(parent[x]);
		}

		
		void join(int x, int y) {
			x = find(x);
			y = find(y);
			
			if (y == x)
				return;
				
			if (size[x] > size[y])
				swap(x, y);
				
			if (mx[x] > mx[y]) {
				mx[y] = mx[x];
				names[y] = names[x];
			}
			
			parent[x] = y;
			size[y] += size[x];
		}
		
		string find_mx(int x) {
			x = find(x);
			
			return names[x];
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	for(int c=1; c <= t; c++) {
		int n, m;
		cin >> n >> m;
		
		vector<int> tolerance(n);
		vector<string> name(n);
		map<string, int> name_id;
		
		for(int i=0; i < n; i++) {
			cin >> name[i] >> tolerance[i];
			
			name_id[name[i]] = i;
		}
		
		DSU dsu(n, tolerance, name);
		
		for(int i=0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
		
			dsu.join(name_id[s1], name_id[s2]);	
		}
		
		vector<bool> vis(n);
		
		cout << "Case " << c << ":\n";
		
		vector<string> ans;
		
		for(int i=0; i < n; i++) {
			int x = dsu.find(i);
			
			if (vis[x])
				continue;
				
			vis[x] = true;
			ans.push_back(dsu.find_mx(x));
		}
		
		sort(ans.begin(), ans.end());
		for(auto &ansi : ans)
			cout << ansi << "\n";
	}
}