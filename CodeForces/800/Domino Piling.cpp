#include <iostream>
using namespace std;

int main() {
  int width, height;
  cin >> width >> height;
  int greater{}, lower{}, total{};

  if (width > height) {
    greater = width;
    lower = height;
  } else {
    greater = height;
    lower = width;
  }

  int qty = greater / 2;
  qty = qty * lower;

  int remainder = ((greater % 2) * lower) / 2;

  total = qty + remainder;

  cout << total;
}