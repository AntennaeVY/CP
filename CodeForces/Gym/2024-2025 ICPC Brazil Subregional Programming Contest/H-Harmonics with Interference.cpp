#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, int m) {
  a %= m;

  long long res = 1;

  while (b) {
    if (b & 1) res *= a, res %= m;

    a *= a, a %= m;
    b >>= 1;
  }

  return res;
}

int getmod(string &s) {
  int ans = 0;

  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0') continue;

    ans += (1 << (s.size() - 1 - i));
  }

  return ans;
}

bool check(string &s, int mod) {
  long long ans = 0;

  for (int i = s.size() - 1; i >= 0; i--) {
  	if (s[i] == '0')
  		continue;
  		
    ans += binpow(2, s.size() - 1 - i, mod);
    ans %= mod;
  }

  return (ans == 0);
}

int main() {
  string m, n;
  cin >> m >> n;

  int cm = count(m.begin(), m.end(), '*');
  int cn = count(n.begin(), n.end(), '*');

  vector<int> pm, pn;

  for (int i = 0; i < m.size(); i++) {
    if (m[i] == '*') pm.push_back(i);
  }

  for (int j = 0; j < n.size(); j++) {
    if (n[j] == '*') pn.push_back(j);
  }

  for (int i = 0; i < (1 << cm); i++) {
    string s1 = m;

    for (int k = 0; k < cm; k++) {
      s1[pm[k]] = '0' + ((i >> k) & 1);
    }

    for (int j = 0; j < (1 << cn); j++) {
      string s2 = n;

      for (int k = 0; k < cn; k++) {
        s2[pn[k]] = '0' + ((j >> k) & 1);
      }

      int mod = getmod(s2);

      if (check(s1, mod)) {
        cout << s1 << endl;
        return 0;
      }
    }
  }
}