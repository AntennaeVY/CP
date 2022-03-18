#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int moves = n - 11;
  int vasya = moves / 2 + moves % 2;
  int petya = moves / 2;

  int cnt = count(s.begin(), s.begin() + moves + 1, '8');

  if (cnt > petya) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}