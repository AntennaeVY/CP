#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int ch = 97;

  int occ = count(s.begin(), s.end(), ch);

  while (occ < k) {
    s.erase(remove(s.begin(), s.end(), char(ch)), s.end());
    k -= occ;
    occ = count(s.begin(), s.end(), char(++ch));
  }

  while (k > 0) {
    for (size_t i{}; i < s.size(); i++) {
      if (s[i] == char(ch) && k > 0) {
        s.erase(i--, 1);
        k--;
      }
    }

    ch++;
  }

  cout << s;
}