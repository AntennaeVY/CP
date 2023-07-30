#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;

  long long ans = 0;

  for (int i{}; i < n; i++) {
    char op;
    int num;

    cin >> op >> num;

    if (op == '+')
      x += num;
    else if (op == '-' && num <= x)
      x -= num;
    else if (op == '-' && num > x)
      ans++;
  }

  cout << x << " " << ans << endl;
}