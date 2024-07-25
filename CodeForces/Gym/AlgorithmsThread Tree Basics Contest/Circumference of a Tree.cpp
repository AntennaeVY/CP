#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 1;

int dist[MAXN];
vector<int> graph[MAXN];


void dfs(int x, int p) {
  for (auto y : graph[x]) {
    if (y == p) continue;

    dist[y] = dist[x] + 1;
    dfs(y, x);
  }
};

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int end = 0;

  dfs(1, 1);

  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[end]) end = i;
  }

  dist[end] = 0;
  dfs(end, end);

  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[end]) end = i;
  }

  printf("%d\n", dist[end] * 3);
}