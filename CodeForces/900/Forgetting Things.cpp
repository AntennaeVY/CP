#include <bits/stdc++.h>
using namespace std;

int main() {
  int da, db;
  cin >> da >> db;

  if (da == 9 && db == 1)
    cout << 99 << " " << 100 << endl;
  else if (db == da)
    cout << da * 10 << " " << db * 10 + 1 << endl;
  else if (db == da + 1)
    cout << da * 10 + 9 << " " << db * 10 << endl;
  else
    cout << -1 << endl;
}