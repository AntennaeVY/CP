#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, W;
    cin >> n >> W;

    vector<int> a(n);
    map<int, int> count;
    map<int, bool> present;

    for (int i = 0; i < n; i++) {
      cin >> a[i];

      count[a[i]] += 1;
      present[a[i]] = true;
    }
    
    int ans = 0;

    while (!count.empty()) {
      int available_space = W;
      
      for (int i = 0; i <= 30; i++) {
        int current_power = (1 << (30 - i));
        
        if (!present[current_power]) continue;
        
        while (count[current_power] && current_power <= available_space) {
        	available_space -= current_power;
        	count[current_power] -= 1;
        } 
        
        if (count[current_power] == 0) {
        	count.erase(current_power);
        	present[current_power] = false;
        }
      }
      
      ans += 1;
    }
    
    cout << ans << endl;
  }
}