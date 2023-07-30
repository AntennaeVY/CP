#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  int maximum{};
  int count{};
  char current = s[0];

  // AAGGGTGTA

  for (int i{}; i < n; i++) {
    if (s[i] == current) {
      count++;
    } else {
      count = 1;
      current = s[i];
    }

    if (count > maximum) {
      maximum = count;
    }
  }

  cout << maximum;

  return 0;
}