#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  unordered_set<int> s;

  for (int i{}; i < k; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }

  if (s.size() == n - 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}