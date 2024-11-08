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
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int ans = 0;
    string match = "1543";

    for (int i = 0; i < min(n,m) / 2; i++) {
      int j = i, k = i;

      string flat = "";

      while (k < m - i) {
        flat += v[j][k];

        k++;
      }

      k--, j++;

      while (j < n - i) {
        flat += v[j][k];

        j++;
      }

      j--, k--;

      while (k >= i) {
        flat += v[j][k];

        k--;
      }

      k++, j--;

      while (j > i) {
        flat += v[j][k];

        j--;
      }

      j++;
      

      flat += flat.substr(0, 3);
      for (int x = 0; x < flat.size(); x++) {
        ans += (flat.substr(x, 4) == match);
      }
    }

    cout << ans << endl;
  }
}