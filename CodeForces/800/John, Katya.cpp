#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "Win" << endl;
  } else if (n == 2) {
    cout << "Draw" << endl;
  } else {
    cout << "Lose" << endl;
  }
}