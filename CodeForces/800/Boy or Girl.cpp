#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;

  int amount{1};

  sort(str.begin(), str.end());

  for (size_t i{}; i < str.size() - 1; i++) {
    if (str[i] != str[i + 1]) {
      amount++;
    }
  }

  if (amount % 2) {
    cout << "IGNORE HIM!";
  } else {
    cout << "CHAT WITH HER!";
  }
}
