#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    vector<int> a(3);
    for (auto &ai : a) cin >> ai;

    sort(a.begin(), a.end());

    bool ok = false;
    for (int i = 0; i < 3; ++i) 
    	ok |= a[i] == a[(i + 1) % 3] + a[(i + 2) % 3];
    for (int i = 0; i < 3; ++i)
      if (a[i] % 2 == 0) 
      	ok |= a[(i + 1) % 3] == a[(i + 2) % 3];
      	
    cout << (ok ? "YES" : "NO") << endl;
  }
}