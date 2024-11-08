#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;

    long long sum = accumulate(a.begin(), a.end(), 0LL);
    
    vector<long long> p(n+1, 0);
    for(int i=0; i < n; i++) {
    	p[i+1] = p[i] + a[i];
    }

    while (q--) {
      long long l, r;
      cin >> l >> r;

      l--, r--;

      long long x = l / n;
      long long y = r / n;

      long long ans = (y - x - 1) * sum;
      
      int L = (x + (l % n)) % n, R = (y + (r % n)) % n;
      
      if (L < x)
      	ans += p[x] - p[L];
      else
      	ans += p[n] - p[L] + p[x];
      
      if (R < y)
      	ans += p[n] - p[y] + p[R+1];
      else
      	ans += p[R+1] - p[y];


      cout << ans << endl;
    }
  }
}