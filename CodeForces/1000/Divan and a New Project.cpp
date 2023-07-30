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

    vector<pair<int, int>> seq;
    for (int i{}; i < n; i++) {
      int x;
      cin >> x;
      seq.push_back(make_pair(x, i));
    }

    sort(seq.begin(), seq.end());

    int hq = 0, left = -1, right = 1;
    long long time = 0;

    for (int i = (int)seq.size() - 1; i >= 0; i--) {
      if (i % 2) {
        time += 2 * (long long)abs(left) * (long long)seq[i].first;
        seq[i].first = left;
        left--;
      } else {
        time += 2 * (long long)right * (long long)seq[i].first;
        seq[i].first = right;
        right++;
      }
    }

    vector<int> coords(n + 1);

    for (size_t i{}; i < seq.size(); i++) {
      coords[seq[i].second + 1] = seq[i].first;
    }

    cout << time << endl;

    for (size_t i{}; i < coords.size(); i++) {
      cout << coords[i] << " ";
    }

    cout << endl;
  }
}