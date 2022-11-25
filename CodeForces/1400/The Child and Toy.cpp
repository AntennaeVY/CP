#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (auto &vi : v) cin >> vi;

  map<int, long long> cost;
  map<int, vector<int>> adj;
  map<int, bool> present;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);

    cost[x] += v[y-1];
    cost[y] += v[x-1];
    
    present[x] = true;
    present[y] = true;
  }

  long long ans = 0;

  for (int i = 1; i <= n; i++) {
    long long max_value = 0;
    int remove;
    
    for (int j = 1; j <= n; j++) {
    	if (!present[j]) continue;
    	
    	if (v[j-1] > max_value) {
    		max_value = v[j-1];
    		remove = j;
    	}
    }

    for(int node : adj[remove]) {
    	cost[node] -= v[remove-1];
    }
    
    ans += cost[remove];
    
    present[remove] = false;
    cost.erase(remove);
  }
  
  cout << ans << endl;
}