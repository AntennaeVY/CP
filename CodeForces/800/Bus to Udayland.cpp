#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, i, x = 0, j;
  cin >> n;
  
  char s[n][5];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 5; j++) {
      cin >> s[i][j];
    }
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < 4; j++) {
      if (s[i][j] == 'O' && s[i][j + 1] == 'O') {
        x = 1;
        s[i][j] = s[i][j + 1] = '+';
        break;
      }
    }
    if (x == 1) break;
  }
  
  if (x == 1) {
    cout << "YES" << endl;
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) {
        cout << s[i][j];
      }
      cout << endl;
    }
  } else
    cout << "NO" << endl;

  return 0;
}