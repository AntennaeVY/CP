#include <bits/stdc++.h>
using namespace std;

constexpr long double EPS = 1e-9;
constexpr long double INF = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long double s, x, y;
  cin >> s >> x >> y;

  long double S, X, Y;
  cin >> S >> X >> Y;

  long double dist = sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
  long double diam = 0;

  x = 0, X = dist;

  long double l = 0, r = dist;
  while (r - l > EPS) {
    long double m = l + (r - l) / 2;

    long double f1 = s / pow(m, 2);
    long double f2 = S / pow(dist - m, 2);

    if (f1 > f2)
      l = m;
    else
      r = m;
  }

  diam += l;

  l = -INF, r = 0;

  while (r - l > EPS) {
    long double m = l + (r - l) / 2;

    long double f1 = s / (m * m);
    long double f2 = S / ((dist - m) * (dist - m));

    if (f1 > f2)
      r = m;
    else
      l = m;
  }

  diam += abs(r);

  cout << fixed << setprecision(6) << M_PI * (diam / 2) * (diam / 2) << endl;
}