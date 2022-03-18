#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int ko = 0, ke = 0, co = 0, ce = 0;

  for (int i{}; i < n; i++) {
    int x;
    cin >> x;

    (x % 2) ? ko++ : ke++;
  }

  for (int i{}; i < m; i++) {
    int x;
    cin >> x;

    (x % 2) ? co++ : ce++;
  }

  cout << (min(ke, co) + min(ko, ce)) << endl;
}