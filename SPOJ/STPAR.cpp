#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;

    vector<int> a(n), stack;

    for (int i{}; i < n; i++) {
      cin >> a[i];
    }

    int counter = 1;
    string ans = "yes";

    for (int i{}; i < n; i++) {
      while (!stack.empty() && stack.back() == counter) {
        stack.pop_back();
        counter++;
      }
    
      if (a[i] == counter)
        counter++;
      else if (!stack.empty() && a[i] > stack.back()) {
        ans = "no";
        break;
      } else
        stack.push_back(a[i]);
    }

    cout << ans << endl;
  }
}