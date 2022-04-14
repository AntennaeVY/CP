#include <math.h>

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  int almost = 0;

  for (int i = 2; i <= n; i++) {
    int j = i;
    int cnt = 0;

    for (int k = 2; k <= j; k++) {
      if (j % k == 0) cnt++;
      while (j % k == 0) j /= k;
    }

    if (cnt == 2) almost++;
  }

  cout << almost;
}