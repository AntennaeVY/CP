#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, t_a, t_b, k;
  cin >> n >> m >> t_a >> t_b >> k;

  vector<int> a(n), b(m);
  for (auto &ai : a) cin >> ai;
  for (auto &bi : b) cin >> bi;

  if (k >= n) {
  	cout << -1 << endl;
  	return 0;
  }
  
  bool can = true;
  int j = -1;
  
  for(int i=0; i <= k; i++) {
	int l = -1, r = m;
	
	while(l + 1 < r) {
		int x = l + (r-l)/2;
		
		if (a[i] + t_a <= b[x])
			r = x;
		else
			l = x;
	}
	
	if (r + (k - i) >= m)
		can = false;
	else
		j = max(j, r + (k - i)); 
  }
  
  if (can)
  	cout << b[j] + t_b << endl;
  else
  	cout << -1 << endl;
}