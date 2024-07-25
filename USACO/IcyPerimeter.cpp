#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  int n;
  cin >> n;

  vector<string> g(n);

  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  vector<vector<bool>> v(n, vector<bool>(n, false));

  int area = 0, perimeter = 0;

  pair<int, int> d[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  function<pair<int,int>(int, int)> dfs;
  dfs = [&](int x, int y) {
  	pair<int,int> p = {1, 0};
  	
    v[x][y] = true;

    for (auto [dx, dy] : d) {
      bool bad = false;
    	
      if (x + dx >= n || x + dx < 0) 
      	 p.second++, bad = true;

      if (y + dy >= n || y + dy < 0) 
      	 p.second++, bad = true;
      	 
      if (bad || v[x + dx][y + dy])
      	continue;

      if (g[x + dx][y + dy] == '.') {
      	p.second++;
      	continue;
      }
      
      pair<int,int> t = dfs(x + dx, y + dy);
      	
      p.first += t.first;
      p.second += t.second;
    }
    
    return p;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == '.' || v[i][j]) 
      	continue;

		pair<int, int> p = dfs(i, j);

      	if (p.first > area)
      		area = p.first, perimeter = p.second;
      	else if (p.first == area)
      		perimeter = min(perimeter, p.second);
    }
  }

  cout << area << " " << perimeter << "\n";
}