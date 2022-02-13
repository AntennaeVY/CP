#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    vector<int> a;
    string ans = "NO";
    cin >> n;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }

    for (int i{}; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        ans = "YES";
        break;
      }
    }

    cout << ans << endl;
  }
}