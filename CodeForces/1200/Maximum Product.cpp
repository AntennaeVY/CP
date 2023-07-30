#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i{}; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end(), cmp);

    long long p1, p2, p3;

    p1 = a[0] * a[1] * a[2] * a[3] * a[4];
    p2 = a[0] * a[1] * a[2] * a[n - 1] * a[n - 2];
    p3 = a[0] * a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4];

    long long ans = max(p3, max(p1, p2));

    cout << ans << endl;
  }
}