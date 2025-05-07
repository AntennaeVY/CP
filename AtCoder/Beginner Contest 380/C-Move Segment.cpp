#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  k--;

  string s;
  cin >> s;

  vector<pair<int, int>> v;

  int l = 0;

  for (int i = 1; i < n; i++) {
    if (s[i] == '1' && s[i - 1] == '0') l = i;

    if (s[i] == '0' && s[i - 1] == '1') {
      v.push_back({l, i - 1});
    }
  }

  if (s[n - 1] == '1') v.push_back({l, n - 1});

  int cnt = v[k].second - v[k].first + 1;

  for (int i = v[k].first; i <= v[k].second; i++) s[i] = '0';

  for (int i = v[k - 1].second + 1; i <= v[k - 1].second + cnt; i++)
    s[i] = '1';

  cout << s << endl;
}