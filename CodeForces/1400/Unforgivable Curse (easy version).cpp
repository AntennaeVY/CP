#include<bits/stdc++.h>
using namespace std;

class DSU {
	private:
		vector<int> parent;
	public:
		vector<vector<int>> cnt;
	
	DSU(string &s) {
		parent.assign((int)s.size(), -1);
		
		cnt.resize((int)s.size());
		fill(cnt.begin(), cnt.end(), vector<int>(26, 0));
		
		for(int i=0; i < s.size(); i++) {
			cnt[i][(int)s[i] - 97]++;
		}
	}
	
	int find(int x) {
		int root = x;
		
		while(parent[root] >= 0)
			root = parent[root];
			
		while(x != root) {
			int next = parent[x];
			parent[x] = root;
			
			x = next;
		}
		
		return root;
	};
	
	void join(int x, int y) { 
		x = find(x), y = find(y);
		
		if (x == y)
			return;
			
		if (y < x)
			swap(x, y);
			
		parent[x] += parent[y];
		parent[y] = x;
		
		for(int i=0; i < 26; i++) {
			cnt[x][i] += cnt[y][i];
		}
	};
};

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s, t;
		cin >> s >> t;
	
		DSU d1(s), d2(t);
		
		for(int i=0; i < n-k; i++) {
			d1.join(i, i+k);
			d2.join(i, i+k);
			
			if (i+k+1 < n)
				d1.join(i, i+k+1), d2.join(i, i+k+1);
		}
		
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < 26; j++) {
				ok &= (d1.cnt[d1.find(i)][j] == d2.cnt[d2.find(i)][j]);
			}
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}