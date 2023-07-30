#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i{}; i < n; i++) {
    cin >> a[i];
  }

  int ans{};

  for (int i{1}; i < n - 1; i++) {
    if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) {
      ans++;
      a[i + 1] = 0;
    }
  }

  cout << ans;
}