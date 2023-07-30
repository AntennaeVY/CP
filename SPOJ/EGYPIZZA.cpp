#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int oh = 0, oq = 0, tq = 0, amount = 1;

  while (n--) {
    string a;
    cin >> a;

    if (a == "1/2")
      oh++;
    else if (a == "1/4")
      oq++;
    else if (a == "3/4")
      tq++;
  }

  amount += oh / 2;
  oh = oh % 2;

  if (oh && oq >= 2) {
    amount += 1;
    oh -= 1;
    oq -= 2;
  }

  int tmp = min(tq, oq);

  amount += tmp;
  tq -= tmp;
  oq -= tmp;

  amount += oq / 4;

  if (oq % 4) amount++;

  amount += oh + tq;

  cout << amount << endl;
}