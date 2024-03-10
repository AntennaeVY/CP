#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  
  while(t--) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(auto &ai : a) cin >> ai;
    
    for (int i=0; i < n; i++) {
      int b;
      cin >> b;
      
      string s;
      cin >> s;
      
      for (int j=0; j < b; j++) {
        if (s[j] == 'U') {
          a[i]--;
          
          if (a[i] == -1) 
            a[i] = 9;
            
        } else {
          a[i]++;
          
          if (a[i] == 10)
            a[i] = 0;
        }
      }
    }
    
    for(auto &ai : a) cout << ai << " ";
    cout << endl;
  }
}