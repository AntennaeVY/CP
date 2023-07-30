#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> a;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }

    sort(a.begin(), a.end());

    cout << a[a.size() - 1] - a[0] << endl;
  }
}