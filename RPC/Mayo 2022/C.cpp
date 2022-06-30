#include <bits/stdc++.h>
using namespace std;

int main() {
  string input;
  getline(cin, input);

  int complexity = 0;

  for (int i{}; i < input.size() - 1; i++) {
    int cnt = 1, mx = 1;
    if (input[i] == ')' || input[i] == ' ') continue;
    for (int j = i + 1; j < input.size(); j++) {
      if (cnt == 0) break;

      if (input[j] == '(') cnt++;

      if (input[j] == ')') cnt--;

      mx = max(cnt, mx);
    }

    complexity += mx;
  }

  cout << complexity << endl;
}
