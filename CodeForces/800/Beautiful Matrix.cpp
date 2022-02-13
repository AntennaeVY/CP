#include <iostream>
using namespace std;

int main() {
  int row{}, column{}, moves{}, number{};

  for (int i{}; i < 5; i++) {
    row = i + 1;
    for (int j{}; j < 5; j++) {
      column = j + 1;
      cin >> number;

      if (number == 1) {
        goto endloop;
      }
    }
  }

endloop:
  moves += abs(3 - row);
  moves += abs(3 - column);
  cout << moves;
}