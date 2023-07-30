#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, N;
  cin >> X >> Y >> N;

  int ans = 0;

  if (Y < 3 * X)
    ans = N / 3 * Y + ((N % 3) * X);
  else
    ans = N * X;

  cout << ans << endl;
}