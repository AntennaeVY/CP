#include <bits/stdc++.h>
using namespace std;

int simulateGame(string s, bool first_in_favor) {
  vector<int> kicks(2, 5), score(2, 0);

  for (int i = 1; i <= 10; i++) {
    if (s[i - 1] == '1' || (s[i - 1] == '?' && i % 2 == first_in_favor)) {
      score[i % 2] += 1;
    }

    kicks[i % 2] -= 1;

    if (score[i % 2] > score[(i + 1) % 2] + kicks[(i + 1) % 2]) return i;

    if (score[i % 2] + kicks[i % 2] < score[(i + 1) % 2]) return i;
  }

  return 10;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int best = 1e9;

    // First team advantage
    best = min(best, simulateGame(s, true));

    // Second team advantage
    best = min(best, simulateGame(s, false));

    cout << best << endl;
  }
}