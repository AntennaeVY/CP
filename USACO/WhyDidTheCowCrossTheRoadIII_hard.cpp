#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> e(100, vector<int>(100));
vector<vector<bool>> cow(100, vector<bool>(100));
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("countcross.in", "r", stdin);
  freopen("countcross.out", "w", stdout);

  int n, k, r;
  cin >> n >> k >> r;

  vector<vector<int>> bad(n, vector<int>(n));
  while (r--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--,y2--;
    
    for (int i = 0; i < 4; i++) {
      int nx = x1 + dx[i];
      int ny = y1 + dy[i];
      if (nx == x2 && ny == y2) {
        bad[x1][y1] |= (1 << i);
      }
    }
    
    for (int i = 0; i < 4; i++) {
      int nx = x2 + dx[i];
      int ny = y2 + dy[i];
      if (nx == x1 && ny == y1) {
        bad[x2][y2] |= (1 << i);
      }
    }
    
  }

  int cnt = 0, ans = 0;

  queue<pair<int, int>> q;

  while (k--) {
    int i, j;
    cin >> i >> j;

    i--, j--;

    q.push({i, j});

    vector<vector<bool>> g(100, vector<bool>(100));
    int good = 0;

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      good += cow[x][y];
      
      for (int i = 0; i < 4; i++) {
        if (bad[x][y] >> i & 1) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || g[nx][ny]) continue;
        q.push({nx, ny});
        g[nx][ny] = 1;
      }
      
    }

    ans += (cnt - good);
    cnt++, cow[i][j] = true;
  }

  cout << ans << endl;
}