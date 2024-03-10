#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    vector<int> p;
    set<int> s;
    
    for (int i=0; i < 2*n; i++) {
      int x;
      cin >> x;
      
      if (s.find(x) != s.end()) 
      	continue;
      	
      s.insert(x);
      p.push_back(x);
    }
    
    int m = p.size();
    
    for (int i=0; i < m; i++) {
      cout << p[i] << " ";
    }
    
    cout << endl;
  }
}