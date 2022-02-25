#include <iostream>
#include <set>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    set<int> a;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      a.insert(x);
    }

    cout << a.size() << endl;
  }
}
