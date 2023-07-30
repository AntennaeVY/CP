#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  
  vector<vector<int>> prefix(18, vector<int>(2e5+10, 0));
  prefix[0][1] = 1;
  
  for(int i=0; i < 18; i++) {
  	for(int j=1<<i; j < 2e5+10; j++) {
  		prefix[i][j] = prefix[i][j-1] + !!(j & 1 << i); 
  	}
  } 
  

  while (t--) {
    int l, r;
    cin >> l >> r;

    int best = 0;

	for(int i=0; i < 18; i++) {
		best = max(best, prefix[i][r] - prefix[i][l-1]);
	}
	
	cout << r-l+1 - best << endl;
  }
}