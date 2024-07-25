#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    int n = 0;
    map<int, vector<int>> g;
    
    for(int i=0; i <= n; i++) {
    	if (a) {
    		g[i].push_back(++n);
    		g[i].push_back(++n);
    		a--;
    	} else if (b) {
    		g[i].push_back(++n);
    		b--;
    	} else {
    		c--;
    	}
    }
    
    if (c != 0) {
    	cout << -1 << endl;
    	continue;
    }
    
    function<int(int)> dfs;
    dfs = [&](int x){
    	if (g[x].size() == 0)
    		return 0;
    		
    	if (g[x].size() == 1)
    		return 1 + dfs(g[x][0]);
    		
    	return 1 + max(dfs(g[x][0]), dfs(g[x][1]));
    };
    
    cout << dfs(0) << endl;
  }
}