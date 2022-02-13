#include <iostream>
using namespace std;

int main() {
  int n{};
  int result{};

  cin >> n;

  while (n--) {
    int a, b, c;

    cin >> a >> b >> c;

    if ((a || b) && (b || c) && ((b == a || b == c) || (a == 1 && c == 1)))
      result++;
  }

  cout << result << endl;
  return 0;
}