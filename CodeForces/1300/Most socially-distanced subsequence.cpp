#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n), b;
    for (auto &ai : a) cin >> ai;

    b.push_back(a[0]);

    int i = 1;

    while (i < n) {
      int current = b.back();
      int minima = 1e9, maxima = 0;
      bool increasing = a[i] > a[i - 1];

      while (i < n && a[i] > a[i - 1] && increasing) {
        maxima = max(a[i], maxima);
        minima = min(a[i], minima);
        i++;
      }

      while (i < n && a[i] < a[i - 1] && !increasing) {
        minima = min(a[i], minima);
        maxima = max(a[i], maxima);
        i++;
      }

      if (abs(current - minima) > abs(current - maxima))
        b.push_back(minima);
      else
        b.push_back(maxima);
    }

    if (b.back() != a.back()) 
      b.push_back(a.back());

    cout << b.size() << endl;

    for (int bi : b) {
      cout << bi << " ";
    }

    cout << endl;
  }
}