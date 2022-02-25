#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int count = 1;
    string s;
    cin >> s;

    string r = s;
    reverse(r.begin(), r.end());

    if (r == s || k == 0) {
      count = 1;
    } else {
      count = 2;
    }

    cout << count << endl;
  }
}