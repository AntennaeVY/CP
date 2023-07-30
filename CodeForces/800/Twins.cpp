#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(int &a, int &b) { return (a > b); }

int main() {
  int n;
  cin >> n;

  vector<int> coins;

  while (n--) {
    int a;
    cin >> a;

    coins.push_back(a);
  }

  sort(coins.begin(), coins.end(), compare);

  int i{-1}, j{coins.size()};
  int sum1{}, sum2{};
  int taken{};

  while (true) {
    if ((sum2 + coins[j - 1]) < sum1 && j - 1 != i) {
      sum2 += coins[j - 1];
      j--;
    } else if ((sum2 + coins[j - 1]) >= sum1 && j - 1 != i) {
      sum1 += coins[i + 1];
      i++;
      taken++;
    } else {
      break;
    }
  }

  cout << taken;
}