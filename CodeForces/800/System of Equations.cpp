#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  int ans = 0;
  
  for(int i=0; i <= 2000; i++) {
    for(int j=0; j <= 2000; j++) {
      if(i * i + j == n && j * j + i == m) {
        ans++;
      }
    }
  }
  
  cout << ans << endl;
}