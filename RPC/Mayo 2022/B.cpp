#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, float> m, c;
  set<string> st;
  map<float, string> r;

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;

    st.insert(s);
    m[s] += i;
    c[s] += 1;
  }

  for (auto x : st) {
    r[m[x] / c[x]] = x;
  }

  for (auto x : r) {
    cout << x.second << endl;
  }
}