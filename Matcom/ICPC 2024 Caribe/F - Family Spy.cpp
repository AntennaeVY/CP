#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  long long x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int xi, yi;
    cin >> xi >> yi;

    x += xi, y += yi;
  }

  for (int i = 0; i < m; i++) {
    int vx, vy;
    cin >> vx >> vy;

    x += n * vx, y += n * vy;
    cout << x << " " << y << endl;
  }
}