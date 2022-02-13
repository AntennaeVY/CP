#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> scores(n);

  for (int i{}; i < n; i++) {
    cin >> scores[i];
  }

  int advances{};
  int score = scores[k - 1];

  for (int i{}; i < n; i++) {
    if (scores[i] >= score && scores[i] > 0) {
      advances++;
    }
  }

  cout << advances;
}