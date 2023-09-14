#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;

  map<int, int> cnt;

  vector<int> a(n);
  for (auto &ai : a) {
    cin >> ai;
    cnt[ai]++;
  }

  sort(a.begin(), a.end());

  deque<pair<int, int>> dq;
  for (auto p : cnt) {
    dq.push_back(p);
  }

  while (k > 0 && dq.size() > 1) {
    int n = dq.size();
    auto x = dq.front(), y = dq.back();

    if (x.second < y.second) {
      long long need = 1LL * (dq[1].first - x.first) * x.second;

      if (k < need) {
      	long long can = k / x.second;
		dq[0].first = x.first + can;
      	
    	break;
      }

      dq[1].second += x.second;
      k -= need;
      dq.pop_front();
    } else {
      long long need = 1LL * (y.first - dq[n - 2].first) * y.second;

      if (k < need) {
      	long long can = k / y.second;
      	dq[n-1].first = y.first - can;
      	
      	break;
      }

      dq[n - 2].second += y.second;
      k -= need;
      dq.pop_back();
    }
  }

  cout << dq.back().first - dq.front().first << endl;
}