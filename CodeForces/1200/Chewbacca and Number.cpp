#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string x;
  cin >> x;

  for (size_t i{}; i < x.size(); i++) {
    if (x[i] >= '5' && !(x[i] == '9' && i == 0)) {
      x[i] = '0' + '9' - x[i];
    }
  }

  if (x[0] == '0') {
    x.erase(0, 1);
  }

  cout << x;
}