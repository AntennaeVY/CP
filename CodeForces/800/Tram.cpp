#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int maximum{}, current{};

  while (n--) {
    int out, in;

    cin >> out >> in;

    current -= out;
    current += in;

    maximum = max(current, maximum);
  }

  cout << maximum;
}