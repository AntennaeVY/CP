#include <bits/stdc++.h>
using namespace std;

int main() {
  long long t;
  cin >> t;

  while (t--) {
    long long n, c, q;
    cin >> n >> c >> q;

    string s;
    cin >> s;
    
    vector<pair<long long, long long>> ops = {{1, n}}, p = {{0, 0}};

    for (int i = 0; i < c; i++) {
      long long x, y;
      cin >> x >> y;

	  auto lst = ops.back();
	
	  p.push_back({x, y});
      ops.push_back({lst.second + 1, lst.second + (y - x + 1)});
    }

    auto char_in_pos = [&](long long k, auto &char_in_pos) {
      if (k <= n) return s[k - 1];

      for (long long i = 0; i <= c; i++) {  
        if (ops[i].second >= k)         
          return char_in_pos(p[i].first + (k-ops[i].first), char_in_pos);
      }
    };

    for (long long i = 0; i < q; i++) {
      long long k;
      cin >> k;

      cout << char_in_pos(k, char_in_pos) << endl;
    }
  }
}