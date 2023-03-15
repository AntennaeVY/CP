#include<bits/stdc++.h>
using namespace std;

class DSU {
	private:
		vector<int> parent;
	public:
		DSU(int size) {
			parent.resize(size);
			fill(parent.begin(), parent.end(), -1);	
		}
		
		int find(int x) {
			if (parent[x] < 0)
				return x;
				
			int root = x;
			while(parent[root] > 0)
				root = parent[root];
				
			// Path compression
			while(x != root) {
				int next = parent[x];
				parent[x] = root;
				x = next;
			}
			
			return x;
		}
			
		int join(int x, int y) {
			if (parent[(x = find(x))] > (parent[(y = find(y))]))
				swap(x,y);
				
			if (x == y)
				return x;
				
			parent[x] += parent[y];
			parent[y] = x;
			
			return x;
		}
		
		int component_size(int x) {
			return abs(parent[find(x)]);
		}
		
};

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		map<int, vector<int>> graph;
		DSU dsu(n);
		
		for(int i=0; i < n; i++) {
			if (i < n-k) {
				dsu.join(i, i+k);
				graph[i].push_back(i+k);
			}
			
			dsu.join(i, n-i-1);
			
			if (i+k != n-i-1 && n-i-1 != i)
				graph[i].push_back(n-i-1);
		}
		
		int ans = 0;
		map<int, bool> visited;
	
		for(int i=0; i < n; i++) {
			if (visited[dsu.find(i)])
				continue;
			
			int max_char = 0;
			map<char, int> cnt;
			queue<int> q;
			
			q.push(dsu.find(i));
			
			// BFS
			while(!q.empty()) {
				int x = q.front();
				q.pop();
				
				if (visited[x])
					continue;
					
				visited[x] = true;
			
				cnt[s[x]]++;
				max_char = max(max_char, cnt[s[x]]);
				
				for(int child : graph[x]) {						
					q.push(child); 
				}
			}
			
			ans += dsu.component_size(i) - max_char;
		}
		
		cout << ans << endl;
	}
}