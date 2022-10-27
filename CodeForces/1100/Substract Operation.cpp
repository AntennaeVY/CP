	/*
		You can always make K if there was initially A,B in the array such that A-B = K
		
		When you substract B, it becomes 0 and A becomes K. After substracting all elements but the element that was initially A, B carries the negative sum of deleted elements so when you delete it you add all elements but B to A so A becomes K again.
	*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, bool> m;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]] = true;
    }

    bool ok = false;

    for (int i = 0; i < n; i++) {
      if (m[k + a[i]]) ok = true;
    }

    cout << (ok ? "YES" : "NO") << endl;
  }
}