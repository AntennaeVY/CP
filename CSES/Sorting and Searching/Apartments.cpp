#include <math.h>

#include <iostream>
#include <set>
using namespace std;

int main() {
  int n, m, k, result{};
  multiset<int> d_as;
  multiset<int> ms;

  cin >> n >> m >> k;

  while (n--) {
    int x;
    cin >> x;
    d_as.insert(x);
  }

  while (m--) {
    int x;
    cin >> x;
    ms.insert(x);
  }

  auto i = d_as.begin();
  auto j = ms.begin();

  // Iterate through sorted elements until it suits the difference and increase
  // the lesser one if it doesn't
  while (i != d_as.end() && j != ms.end()) {
    if (abs(*i - *j) <= k) {
      result++;
      i++;
      j++;
    } else if (*i < *j) {
      i++;
    } else {
      j++;
    }
  }

  cout << result;
}