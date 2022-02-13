#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string word;
  cin >> word;

  int uppercase_count{}, lowercase_count{};
  bool up;

  for (int i{}; i < word.size(); i++) {
    if (isupper(word[i])) {
      uppercase_count++;
    } else {
      lowercase_count++;
    }
  }

  if (uppercase_count > lowercase_count) {
    up = true;
  } else {
    up = false;
  }

  for (int i{}; i < word.size(); i++) {
    if (up) {
      word[i] = toupper(word[i]);
    } else {
      word[i] = tolower(word[i]);
    }
  }

  cout << word;
}