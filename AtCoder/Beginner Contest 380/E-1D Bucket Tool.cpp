#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 5e5+5;

int parent[MAXN];
int sz[MAXN];
int color[MAXN];


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (a < b)
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	for(int i=1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
		color[i] = i;
	}
	
	vector<int> ans(n+1, 1);
	
	while(q--) {
		int t;
		cin >> t;
		
		if (t == 1) {
			int x, c;
			cin >> x >> c;
			
			int p = find_set(x);
			int size = sz[p];
			
			ans[color[p]] -= size;
			color[p] = c;
			ans[color[p]] += size;
			
			if (color[find_set(p-size)] == c)
				union_sets(p - size, p);
			
			if (color[find_set(p+1)] == c)
				union_sets(p, p+1);
				
		} else {
			int c;
			cin >> c;
			
			cout << ans[c] << endl;
		}
		
	
	}
}