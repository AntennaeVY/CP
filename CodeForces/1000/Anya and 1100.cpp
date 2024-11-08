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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int n = s.size();

    set<int> st;
    for (int i = 0; i < n - 3; i++) {
      if (s.substr(i, 4) == "1100") st.insert(i);
    }

    int q;
    cin >> q;

    while (q--) {
      int i;
      char v;

      cin >> i >> v;
      i--;

      if (s[i] != v) {
        s[i] = v;

        for (int j = 0; j < 4; j++) {
          st.erase(i + j);
          st.erase(i - j);
        }

        for (int j = 0; j < 4; j++) {
          if (i-j >= 0 && i-j < n && s.substr(i - j, 4) == "1100") 
          	st.insert(i - j);

          if (i+j >= 0 && i+j < n && s.substr(i + j, 4) == "1100") 
          	st.insert(i + j);
        }
      }

      cout << (!st.empty() ? "YES" : "NO") << endl;
    }
  }
}