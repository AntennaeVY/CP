#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s, t;
    cin >> s >> t;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int si = stoi(s);
    int ti = stoi(t);

    int sum = si + ti;

    string u = to_string(sum);

    reverse(u.begin(), u.end());

    cout << stoi(u) << endl;
  }
}