#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    vector<int> dis(4);

    for (int i{}; i < 4; i++) {
      cin >> dis[i];
    }

    int timur = dis[0];

    sort(dis.begin(), dis.end());

    for (int i{}; i < 4; i++) {
      if (dis[i] == timur) cout << 3 - i << endl;
    }
  }
}