#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;

    map<long long, long long> cnt = {{0, 1}};
	long long sum = 0;
	
	bool ok = false;
    
    for (int i=0; i < n; i++) {
      a[i] *= ((i % 2) ? -1 : 1);
      
      sum += a[i];
    	
	  ok |= cnt[sum]++;
    
    }
    
    cout << (ok ? "YES" : "NO") << endl;
  }
}