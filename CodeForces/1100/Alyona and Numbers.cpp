#include <math.h>

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<long long> modsN(5, 0), modsM(5, 0);

  for (int i = 1; i <= n; i++) {
    modsN[i % 5]++;
  }

  for (int i = 1; i <= m; i++) {
    modsM[i % 5]++;
  }

  cout << modsN[0] * modsM[0] + modsN[1] * modsM[4] + modsN[2] * modsM[3] +
              modsN[3] * modsM[2] + modsN[4] * modsM[1];
}