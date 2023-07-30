#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;

int main() {
  double r, s, h, m, d, vt, v, ang, coffee_r;

  cin >> r >> s >> h >> m >> d;

  vt = h * M_PI / 3 * (s * s + r * r + r * s);
  ang = atan(h / (s - r));
  coffee_r = (d / tan(ang)) + r;

  v = d * M_PI / 3 * (coffee_r * coffee_r + r * r + coffee_r * r);

  double vpm = (vt - v) / m;

  cout << fixed << setprecision(9);
  cout << v / vpm << endl;
}