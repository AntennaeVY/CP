#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    if (count(t.begin(), t.end(), 'o')) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}