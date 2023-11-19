#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  multiset<int> ml, mr;

  while (q--) {
    char op;
    int l, r;

    cin >> op >> l >> r;

    if (op == '-') {
      ml.erase(ml.find(l));
      mr.erase(mr.find(r));
    } else {
      ml.insert(l);
      mr.insert(r);
    }

	if (ml.empty() && mr.empty()) {
		cout << "NO" << endl;
		continue;
	}
	
    int L = *prev(ml.end());
    int R = *mr.begin();

    cout << (L > R ? "YES" : "NO") << endl;
  }
}