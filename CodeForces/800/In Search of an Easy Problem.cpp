#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string ans = "EASY";

  while (n--) {
    int i;
    cin >> i;

    if (i) {
      ans = "HARD";
      break;
    }
  }

  cout << ans;
}