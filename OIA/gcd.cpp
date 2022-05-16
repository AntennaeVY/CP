#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  gcd(b, a % b);
}

int gcdIt(int a, int b) {
  if (a < b) {
    swap(a, b);
  }

  if (b == 0) return a;

  while (a % b != 0) {
    a = a % b;

    swap(a, b);
  }

  return a;
}

int main() {
  int a, b;
  cin >> a >> b;

  gcd(a, b);
}