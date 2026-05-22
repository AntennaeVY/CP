#include<bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<int>> adj;
vector<char> labels;
vector<string> prefix;
vector<string> xiferp;
vector<int> level;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

void build_prefix(int u, int p = -1, int l = 0) {
	if (p == -1) {
		prefix[u] = labels[u];
	} else {
		prefix[u] = prefix[p] + labels[u];
	}
	
	level[u] = l;
	xiferp[u] = prefix[u];
	
	reverse(xiferp[u].begin(), xiferp[u].end()); 
	
	for(auto v : adj[u])
		if (v != p)
			build_prefix(v, u, l+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	adj.resize(n);
	labels.resize(n);
	prefix.resize(n);
	level.resize(n);
	xiferp.resize(n);
	
	for(int i=0; i < n; i++) {
		cin >> labels[i];
	}
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	build_prefix(0);
	preprocess(0);
	
	unordered_set<string> s;
	
	for(int i=0; i < n; i++) {
		s.insert(to_string(labels[i]));
		
		for(int j=i+1; j < n; j++) {
			int p = lca(i, j);
			
			string pu = prefix[i].substr(level[p]);
			string pv = prefix[j].substr(level[p]);
			
			string ru = xiferp[i].substr(0, level[i] - level[p]);
			string rv = xiferp[j].substr(0, level[j] - level[p]);
			
			// cout << i << " " << j << " " << endl;
			// cout << ru + pv << endl;
			// cout << rv + pu << endl;
			// cout << endl;
			
			s.insert(ru + pv);
			s.insert(rv + pu);
		}
	}
	
	cout << s.size() << "\n";
}