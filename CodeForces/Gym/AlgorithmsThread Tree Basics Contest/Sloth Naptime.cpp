#include<bits/stdc++.h>
using namespace std;

const int LOG = 20;
const int MAXN = 3e5 + 1;
int t = 0;

vector<int> G[MAXN];
int up[MAXN][LOG+1];
int tin[MAXN], tout[MAXN];
int depth[MAXN];

void dfs(int u, int p = -1, int d = 0) {
	tin[u] = t++;
	depth[u] = d;
	
	up[u][0] = p;
	
	for(int i=1; i < LOG; i++) {
		if (up[u][i-1] == -1)
			break;
			
		up[u][i] = up[up[u][i-1]][i-1];
	}
	
	
	for(int v : G[u])
		if (v != p)
			dfs(v, u, d+1);

	tout[u] = t;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int kth_ancestor(int k, int u) {
	for(int i = 0; i < LOG; i++) {
		if (((k >> i) & 1) == 0)
			continue;
			
		if (u != -1)
			u = up[u][i];
	}
	
	return u;
}

int LCA(int u, int v) {
	int lca = u;
	
	for(int i = LOG; i >= 0; i--) {
		if (up[lca][i] == -1)
			continue;
			
		if (!is_ancestor(up[lca][i], v))
			lca = up[lca][i];
	}
			
	return lca = up[lca][0];
}


int main() {
	fill(depth, depth + MAXN, 0);
	fill(tin, tin + MAXN, 0);
	fill(tout, tout + MAXN, 0);
	fill(G, G+MAXN, vector<int>());
	
	for(int i = 0; i < MAXN; i++)
		fill(up[i], up[i] + LOG + 1, -1);

		
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1);
	
	int q;
	scanf("%d", &q);
	
	while(q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		if (is_ancestor(a, b)) {
			
			int d = depth[b] - depth[a];
			int k = d - min(d, c);
		
			printf("%d\n", kth_ancestor(k, b));
			
		} else if (is_ancestor(b, a)) {
			
			int d = depth[a] - depth[b];
			int k = min(d, c);

			printf("%d\n", kth_ancestor(k, a));
			
		} else {
			
			int lca = LCA(a, b);
			
			// Calculate max allowed lifts from A to LCA
			int da = depth[a] - depth[lca];
			int ka = min(da, c);
			
			// Calculate max allowed lifts from B to LCA
			int db = depth[b] - depth[lca];
			int kb = db - min(db, c - ka);
			
			
			if (c <= da) 
				printf("%d\n", kth_ancestor(ka, a));
			else
				printf("%d\n", kth_ancestor(kb, b));
			
		}	
	}
}