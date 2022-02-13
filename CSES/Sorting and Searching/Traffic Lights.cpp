#include <math.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;

  multiset<int> gaps;
  set<int> tl;

  gaps.insert(x);
  tl.insert(0);
  tl.insert(x);

  while (n--) {
    int z;
    cin >> z;
    tl.insert(z);

    auto it = tl.lower_bound(z), pv = prev(it), nx = next(it);
    int old_d = abs(*pv - *nx);
    gaps.erase(gaps.lower_bound(old_d));
    gaps.insert(abs(*pv - *it));
    gaps.insert(abs(*it - *nx));

    cout << *(--gaps.end()) << " ";
  }
}