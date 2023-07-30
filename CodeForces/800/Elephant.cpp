#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;

  int remainder, divisor = 5, result, steps{};

  while (x) {
    remainder = x % divisor;
    result = x / divisor;

    steps += result;
    x = remainder;
    divisor--;
  }

  cout << steps;
}