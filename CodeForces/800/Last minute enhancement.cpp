#include <iostream>
#include <set>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    set<int> s;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;

      if (s.count(x)) {
        s.insert(x + 1);
      } else {
        s.insert(x);
      }
    }

    cout << s.size() << endl;
  }
}