#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  unordered_set<int> s;

  int n;
  cin >> n;

  s.insert(n);

  while (true) {
    n++;
    while (n % 10 == 0) n /= 10;

    if (s.count(n)) {
      break;
    } else {
      s.insert(n);
    }
  }

  cout << s.size() << endl;
}