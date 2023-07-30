#include <bits/stdc++.h>
using namespace std;

set<int> repeated;
map<int, int> freq;

bool good(vector<int> &a, int k) {
  set<int> s;
  map<int, int> m;

  int l = 0, n = a.size(), cnt = 0;

  for (int r{}; r < n; r++) {
    m[a[r]]++;

    if (m[a[r]] >= freq[a[r]] - 1 && repeated.count(a[r])) {
      s.insert(a[r]);
    }

    while (r - l + 1 > k) {
      m[a[l]]--;

      if (m[a[l]] < freq[a[l]] - 1 && repeated.count(a[l])) {
        s.erase(a[l]);
      }

      l++;
    }

    if (s.size() == repeated.size()) return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i{}; i < n; i++) {
    cin >> a[i];

    freq[a[i]]++;
  }

  for (auto x : freq) {
    if (x.second > 1) repeated.insert(x.first);
  }

  if (repeated.empty()) {
    cout << 0 << endl;
    return 0;
  }

  int l = 0, r = n;

  while (l + 1 < r) {
    int mid = l + (r - l) / 2;

    if (good(a, mid))
      r = mid;
    else
      l = mid;
  }

  cout << r << endl;
}