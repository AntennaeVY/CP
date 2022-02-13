#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    int zero_count = 0;
    int one_count = 0;

    for (int i{}; i < s.length(); i++) {
      if (s[i] == '0') {
        zero_count++;
      } else {
        one_count++;
      }
    }

    if (zero_count == one_count) {
      if (s[s.length() - 1] == '1') {
        one_count--;
      } else {
        zero_count--;
      }
    }

    if (zero_count < one_count) {
      cout << zero_count << endl;
    } else if (one_count < zero_count) {
      cout << one_count << endl;
    } else {
      cout << 0 << endl;
    }
  }
}