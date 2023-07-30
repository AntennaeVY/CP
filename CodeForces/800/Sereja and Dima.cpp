#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (auto &it : a) cin >> it;

  int l = 0, r = n - 1;

  long long sereja = 0, dima = 0;

  for (int i = 0; i < n; i++) {
    int num = 0;

    if (a[l] > a[r]) {
      num = a[l];
      l++;
    } else {
      num = a[r];
      r--;
    }

    if (i % 2) {
      dima += num;
    } else {
      sereja += num;
    }
  }

  cout << sereja << " " << dima << endl;
}