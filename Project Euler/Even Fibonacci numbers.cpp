#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  long current = 0, next = 2, sum = 0;

  while (next <= n) {
    current = next;
    next = round(current * pow((1 + sqrt(5)) / 2, 3));
    sum += current;
  }

  cout << sum;
}