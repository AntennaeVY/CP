#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> seq;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;
      seq.push_back(x);
    }

    sort(seq.begin(), seq.end());

    for (int i = 1; i <= n / 2; i++) {
      cout << seq[i] << " " << seq[0] << endl;
    }
  }
}