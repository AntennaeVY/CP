#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  bool rem{};

  for (int i{}; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      s.erase(i, 1);
      rem = true;
      break;
    }
  }

  if (!rem) {
    for (int i{n - 1}; i > 0; i--) {
      if (s[i] >= s[i - 1]) {
        s.erase(i, 1);
        break;
      }
    }
  }

  cout << s;
}