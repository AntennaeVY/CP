#include <bits/stdc++.h>
using namespace std;


bool is_prime(int x) {
	if (x <= 1)
		return false;
	
	for(int i=2; i*i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	
	return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int x, k;
    cin >> x >> k;

    if (x != 1 && k > 1) {
      cout << "NO" << endl;
      continue;
    }

    if (x == 1) {
      cout << (k == 2 ? "YES" : "NO") << endl;
    } else {
      cout << (is_prime(x) ? "YES" : "NO") << endl;
    }
  }
}