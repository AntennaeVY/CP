#include <iostream>
#include <iterator>
using namespace std;

int main() {
  string s;
  cin >> s;

  string match = "hello";
  int k = 0;
  bool ok = false;

  for (size_t i{}; i < s.size(); i++) {
    if (s[i] == match[k]) {
      k++;
    }

    if (k == 5) {
      ok = true;
    }
  }

  if (ok) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}