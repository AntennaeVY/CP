#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  if (
  	  s.size() - 1 > t.size() || 
  	  count(s.begin(), s.end(), '*') == 0 && s != t
  ) {
    cout << "NO" << endl;
    return 0;
  }

  if (s == t) {
    cout << "YES" << endl;
    return 0;
  }
  
  bool ok = true;
  int asterisk = 0;
  
  for(int i=0; i < s.size(); i++) {
  	if (s[i] == '*')
  		asterisk = i;
  }
  
  for(int i=0; i < asterisk; i++) {
  	if (s[i] != t[i])
  		ok = false;
  }
  
  int i = s.size()-1, j = t.size()-1;
  
  while(i > asterisk) {
  	if (s[i] != t[j])
  		ok = false;
  		
  	i--;
  	j--;
  }
  
  cout << (ok ? "YES" : "NO") << endl;
}