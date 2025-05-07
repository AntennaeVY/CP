#include <bits/stdc++.h>
using namespace std;

class DSU {
  vector<int> p, size;
  vector<bool> bad;
  vector<long long> edges;

 public:
  DSU(int n) {
    p.assign(n + 1, -1);
    size.assign(n + 1, 1);
	bad.assign(n+1, false);
	edges.assign(n+1, 0);
  }

  int find(int x) {
    if (p[x] == -1) 
    	return x;

    return p[x] = find(p[x]);
  }

  void join(int x, int y) {
    x = find(x), y = find(y);

    if (size[x] < size[y]) 
    	swap(x, y);

    if (x == y) {
    	edges[x] += 1;
    	return;
    }

    p[y] = x;
    size[x] += size[y];
    edges[x] += edges[y] + 1;
  }

  int size_of(int x) { 
  	return size[x]; 
  }
  
  void mark_bad(int x) {
  	bad[find(x)] = true;
  }
  
  bool is_bad(int x) {
  	return bad[find(x)];
  }
  
  long long edges_of(int x) {
  	return edges[find(x)];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  long long k;
  cin >> n >> m >> k;

  set<pair<int, int>> s;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    s.insert({x, y});
  }

  DSU dsu(n);

  for (auto &[x, y] : s) {
    if (s.count({y, x})) {
    	dsu.join(x, y);
    } else {
    	dsu.mark_bad(x);
    	dsu.mark_bad(y);
    }
  }

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    if (dsu.find(i) == i && !dsu.is_bad(i)) {
    	ans += (dsu.size_of(i) == k && dsu.edges_of(i) == k*(k-1));
    }
  }

  cout << ans << endl;
}