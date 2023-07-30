#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    string s;
    cin >> s;

    map<char, int> m;

    for (int i = 0; i < s.size(); i++) {
      m[s[i]]++;
    }
    
    

    if (!(m['L'] && m['R']) && !(m['D'] && m['U'])) {
      cout << 0 << endl << endl;
      continue;
    }
    
    if (!(m['L'] && m['R'])) {
    	m['D'] = 1;
    } else if (!(m['U'] && m['D']))
    	m['L'] = 1;

    cout << 2*min(m['L'], m['R']) + 2*min(m['U'], m['D']) << endl;

    string ans = "";

    ans += string(min(m['U'], m['D']), 'U');
    ans += string(min(m['R'], m['L']), 'R');
    ans += string(min(m['U'], m['D']), 'D');
    ans += string(min(m['R'], m['L']), 'L');
    
    cout << ans << endl;
  }
}