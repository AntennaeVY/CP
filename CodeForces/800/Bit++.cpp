#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, x{};
  cin >> n;

  while (n--) {
    string statement{};
    cin >> statement;

    if (statement[1] == '+') {
      x++;
    } else if (statement[1] == '-') {
      x--;
    }
  }

  cout << x;
}