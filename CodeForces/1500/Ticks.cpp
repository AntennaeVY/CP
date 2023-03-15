#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;

    int asterisks = 0;
    map<pair<int, int>, bool> visited;
    vector<string> field(n);

    for (int i = 0; i < n; i++) {
      cin >> field[i];

      asterisks += count(field[i].begin(), field[i].end(), '*');
    }

    function<bool(int, int)> check;
    function<void(int, int)> mark;

    check = [&](int i, int j) {
      int length = 0;

      while (i-1 >= 0 && j-1 >= 0 && j+1 + 2*length < m) {
        if (field[i-1][j-1] != '*' || field[i-1][j+1 + 2*length] != '*')
        	break;

        length++;
        i--;
        j--;
      }

      return length >= k;
    };

    mark = [&](int i, int j) {
      int length = 0;
      
      visited[{i, j}] = true;

      while (i-1 >= 0 && j-1 >= 0 && j+1 + 2*length < m) {
        if (field[i-1][j-1] != '*' || field[i-1][j+1 + 2*length] != '*')
        	break;

        visited[{i-1, j-1}] = true;
        visited[{i-1, j+1 + 2*length}] = true;

        length++;
        i--;
        j--;
      }
    };

    for (int i = k - 1; i < n; i++) {
      for (int j = k - 1; j < m; j++) {
		if (field[i][j] != '*' || !check(i, j))
			continue;
			
		mark(i, j);
      }
    }

    cout << (visited.size() == asterisks ? "YES" : "NO") << endl;
  }
}