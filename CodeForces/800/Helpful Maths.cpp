#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str{};
  cin >> str;

  vector<int> v;

  for (size_t i{}; i < str.size(); i++) {
    char a = str[i];

    if (a != '+') {
      int x = a - '0';
      v.push_back(x);
    }
  }

  sort(v.begin(), v.end());

  for (size_t i{}; i < v.size(); i++) {
    if (i == v.size() - 1) {
      cout << v[i];
    } else {
      cout << v[i] << '+';
    }
  }
}