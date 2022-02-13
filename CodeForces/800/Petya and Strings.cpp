#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string str1{}, str2{};
  int result{};
  cin >> str1 >> str2;

  for (size_t i{}; i < str1.size(); i++) {
    str1[i] = tolower(str1[i]);
    str2[i] = tolower(str2[i]);
  }

  // sort(str1.begin(), str1.end());
  // sort(str2.begin(), str2.end());

  for (size_t i{}; i < str1.size(); i++) {
    if (str1[i] < str2[i]) {
      result = -1;
      break;
    } else if (str1[i] > str2[i]) {
      result = 1;
      break;
    }
  }

  cout << result;
}