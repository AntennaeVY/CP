#include <iostream>
#include <iterator>
#include <queue>
#include <set>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  multiset<int> ms;
  queue<int> q;

  while (n--) {
    int x;
    cin >> x;
    ms.insert(x);
  }

  for (int i{}; i < m; i++) {
    int x;
    cin >> x;
    q.push(x);
  }

  // The first element <= x is the element before the first element > x
  for (int i{}; i < m; i++) {
    int e = q.front();
    auto it = ms.upper_bound(e);

    if (it == ms.begin()) {
      cout << "-1" << endl;
      q.pop();
    } else {
      cout << *(prev(ms.upper_bound(e))) << endl;
      ms.erase(ms.lower_bound(*(prev(ms.upper_bound(e)))));
      q.pop();
    }
  }
}