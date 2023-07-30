#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> d{6, 8, 4, 2};

  if (n)
    cout << d[n % 4];
  else
    cout << 1;
}