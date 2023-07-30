#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, int> r;

  for (int j{}; j < n; j++) {
    string s;
    cin >> s;

    auto it = r.find(s);

    if (it != r.end()) {
      it->second += 1;
      cout << it->first + to_string(it->second) << endl;
    } else {
      cout << "OK" << endl;
      r[s] = 0;
    }
  }
}