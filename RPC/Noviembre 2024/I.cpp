#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) int((x).size())
#define READARR(x) \
  for (auto &xi : (x)) cin >> xi;
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define vi vector<int>
#define vll vector<long long>
#define ll long long

template <class x>
ostream &operator<<(ostream &out, vector<x> v) {
  out << "[ ";
  for (auto y : v) out << y << " ";
  out << "]";
  return out;
}

string add(string x, string y) {
  int n = x.size();
  int m = y.size();

  string z = "";

  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());

  bool carry = false;

  for (int i = 0; i < max(n, m); i++) {
    z += (carry ? '1' : '0');
    carry = false;

    if (i < n && x[i] == '1') {
      carry |= (z[i] == '1');

      z[i] = z[i] ^ '1' ^ '0';
    }

    if (i < m && y[i] == '1') {
      carry |= (z[i] == '1');

      z[i] = z[i] ^ '1' ^ '0';
    }
  }

  if (carry) z += '1';

  reverse(z.begin(), z.end());
  return z;
};

string to_bin(int n) {
  if (n == 0) return "0";

  string ans = "";

  while (n) {
    ans += '0' + (n % 2);
    n /= 2;
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;

  while (t--) {
    string s, d, m;
    cin >> s >> d >> m;

    int D = 0;
    for (int i = d.size() - 1; i >= 0; i--) {
      if (d.size() - i - 1 >= 32)
      	D = 2e9;
      	
      if (D > m.size()) break;
    
      if (d[i] == '1') D += (1 << (d.size() - i - 1));

    }
    
    // cout << D << endl;

    if (D > m.size()) {
 	  cout << to_bin(m.size()) << endl;
      
      continue;
    }

    string startingFirstDAmount = m.substr(0, m.size() - D);
    string endingFirstDAmount = add(startingFirstDAmount, s);
    int diff = endingFirstDAmount.size() - startingFirstDAmount.size();

    if (diff - D >= 0) {
      cout << "Infinite money!" << endl;
      continue;
    }
    
    int bits = endingFirstDAmount.size();
    int ans = D;
    
    while(bits - D >= 0)
    	bits += (diff - D), ans += D;
    	
    ans += bits;

    cout << to_bin(ans) << endl;
  }
}