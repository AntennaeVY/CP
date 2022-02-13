#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<long long> v;

    for (int i{}; i < n; i++) {
      long x;
      cin >> x;

      v.push_back(x);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
      while ((v[i] % 2) == 0) {
        v[i] /= 2;
        k++;
      }
    }

    sort(v.begin(), v.end());

    v[v.size() - 1] *= pow(2, k);

    long long sum = 0;

    for (int i{}; i < n; i++) {
      sum += v[i];
    }

    cout << sum << endl;
  }
}