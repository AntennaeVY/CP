#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int m, n;
    cin >> m >> n;

    vector<int> maxima(n, 0);
    vector<vector<int>> table(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> table[i][j];

        maxima[j] = max(maxima[j], table[i][j]);
      }
    }

    if (n > m) {
      cout << *min_element(maxima.begin(), maxima.end()) << endl;
      continue;
    }

	int minima = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = j+1; k < n; k++) {
			minima = max(minima, min(table[i][j], table[i][k]));
        }
      }
    }
    
    cout << min(*min_element(maxima.begin(), maxima.end()), minima) << endl;
  }
}