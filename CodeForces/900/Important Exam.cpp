#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> grades;
  vector<int> a;

  for (int i{}; i < n; i++) {
    string x;
    cin >> x;
    grades.push_back(x);
  }

  for (int i{}; i < m; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  int ans = 0;

  for (int i{}; i < m; i++) {
    int A = 0, B = 0, C = 0, D = 0, E = 0;

    for (int j{}; j < n; j++) {
      if (grades[j][i] == 'A') {
        A++;
      } else if (grades[j][i] == 'B') {
        B++;
      } else if (grades[j][i] == 'C') {
        C++;
      } else if (grades[j][i] == 'D') {
        D++;
      } else if (grades[j][i] == 'E') {
        E++;
      }
    }

    ans += a[i] * max({A, B, C, D, E});
  }

  cout << ans;
}