#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> ady(N + 1);

  for (int b = 1; b <= N; b++) {
    int a;
    cin >> a;
    ady[a += (a == -1)].push_back(b);
  }

  vector<int> dist(N + 1, -1);
  queue<int> q;

  dist[0] = 0, q.push(0);

  int ans = 0;

  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto b : ady[a]) {
      if (dist[b] == -1) {
        dist[b] = dist[a] + 1;
        ans = max(ans, dist[b]);
        q.push(b);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
