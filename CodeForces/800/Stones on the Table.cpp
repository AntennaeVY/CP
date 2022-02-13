#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, takes{};
  string str;

  cin >> n >> str;

  for (int i{}; i < n - 1; i++) {
    if (str[i] == str[i + 1]) {
      takes++;
    }
  }

  cout << takes;
}