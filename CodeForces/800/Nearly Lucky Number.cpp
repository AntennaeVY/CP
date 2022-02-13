#include <iostream>
#include <string>
using namespace std;

int main() {
  string n;
  cin >> n;

  string ans = "YES";
  int cnt = 0;

  for (size_t i{}; i < n.size(); i++) {
    if (n[i] == '7' || n[i] == '4') {
      cnt++;
    }
  }

  string cnt_s = to_string(cnt);

  for (size_t i{}; i < cnt_s.size(); i++) {
    if (cnt_s[i] != '7' && cnt_s[i] != '4') {
      ans = "NO";
    }
  }

  cout << ans << endl;
}