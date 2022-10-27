#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int mx = 0;
  vector<int> m(1e6+3, 0);

  for (int i{}; i < n; i++) {
    int x;
    cin >> x;

    m[x]++;
    mx = max(x, mx);
  }

  for(int i=mx; i >= 1; i--) {
  	int cnt = 0;
  	for(int j=i; j <= mx; j += i) {
  		cnt += m[j];
  	}
  	
  	if (cnt >= 2) {
  		cout << i << endl;
  		break;
  	}
  }
  
}