#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int pos = 0;

  for (char c : s2) {
    if (s1[pos] == c) pos++;
  }

  cout << pos + 1 << endl;
}