#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;

  while (Q--) {
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i{}; i < n; i++) {
      cin >> s[i];
    }

    int even = 0, bad = 0, odd = 0;

    for (int i{}; i < n; i++) {
      int ones = count(s[i].begin(), s[i].end(), '1');
      int zeroes = count(s[i].begin(), s[i].end(), '0');

      if (s[i].size() % 2 == 0) {
        if (ones % 2 || zeroes % 2) {
          bad++;
        } else {
          even++;
        }
      } else {
        odd++;
      }
    }

    cout << n - (odd == 0 && bad % 2 == 1 ? 1 : 0) << endl;
  }
}