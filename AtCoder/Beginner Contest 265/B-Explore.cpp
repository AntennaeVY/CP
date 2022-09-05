#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, M, T;
  cin >> N >> M >> T;

  vector<int> A(N - 1);
  for (int &a : A) cin >> a;

  queue<pair<int, int>> q;
  for (int i{}; i < M; i++) {
    int x, y;
    cin >> x >> y;

    q.push(make_pair(x, y));
  }

  bool ans = true;

  for (int i = 0; i < N - 1; i++) {
    auto b = q.front();
    T -= A[i];

    if (!q.empty() && b.first == i + 1) {
      T += b.second;
      q.pop();
    }

    if (T <= 0) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << endl;
}