#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
  int n;
  // unordered_set<int> s; // Should be faster O(1)
  set<int> s;  // O(log(n))
  cin >> n;

  while (n--) {
    int x;
    cin >> x;

    s.insert(x);
  }

  cout << s.size();
}