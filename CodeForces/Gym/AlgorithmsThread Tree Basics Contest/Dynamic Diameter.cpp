#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 1;

int dist_a[MAXN], dist_b[MAXN], dist_1[MAXN];
vector<int> graph[MAXN];

void dfs(int dist[], int u, int p = 0) {
	for(auto v : graph[u]) {
		if (v == p)
			continue;
			
		dist[v] = dist[u] + 1;
		dfs(dist, v, u);
	}	
}

int main() {
	int n;
	scanf("%d", &n);
	
	for(int i=0; i < n; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	// me da tock usar dist_b xd
	dfs(dist_1, 1);
	
	int a = 0;
	
	for(int i = 1; i <= n; i++) {
		if (dist_1[i] > dist_1[a])
			a = i;
	}
	
	dfs(dist_a, a);

	int b = 0;
	
	for(int i = 1; i <= n; i++) {
		if (dist_a[i] > dist_a[b])
			b = i;
	}

	dfs(dist_b, b);
	
	for(int i = 1; i <= n; i++) {
		int ans = max(max(dist_a[i], dist_b[i]) + 1, dist_a[b]);

		printf("%d\n", ans);
	}
}