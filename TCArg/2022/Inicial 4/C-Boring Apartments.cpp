#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<string> apts;

  for (int i = 1; i < 10; i++) {
    int num = 0;
    for (int j = 0; j < 4; j++) {
      num += i * pow(10, j);
      apts.push_back(to_string(num));
    }
  }

  vector<int> ps(apts.size() + 1, 0);

  for (int i = 1; i < apts.size() + 1; i++) {
    ps[i] = ps[i - 1] + apts[i - 1].size();
  }

  while (t--) {
    string x;
    cin >> x;

    for (int i{}; i < apts.size(); i++) {
      if (apts[i] == x) {
        cout << ps[i + 1] << endl;
        break;
      }
    }
  }
}