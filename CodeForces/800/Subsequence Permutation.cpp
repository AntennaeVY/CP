#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k{};
    string s, cpy;

    cin >> n >> s;
    cpy = s;

    sort(cpy.begin(), cpy.end());

    for (int i{}; i < n; i++) {
      if (s[i] != cpy[i]) {
        k++;
      }
    }

    cout << k << endl;
  }
}