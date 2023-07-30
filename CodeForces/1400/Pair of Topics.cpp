#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (auto &ai : a) cin >> ai;
  for (auto &bi : b) cin >> bi;

  long long ans = 0;
  vector<int> s(n);
  
  for (int i = 0; i < n; i++) {
	s[i] = a[i] - b[i];
  }
  
  sort(s.begin(), s.end());
  
  for(int i=0; i < n; i++) {
  	if (s[i] <= 0)
  		continue;
  		
  	ans += i - (int)(lower_bound(s.begin(), s.end(), -s[i] + 1) - s.begin());
  }

  cout << ans << endl;
}