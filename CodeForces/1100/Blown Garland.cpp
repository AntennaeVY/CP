#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  map<char, int> m;

  for (int x = 0; x < 4; x++) {
  	char c = '?';
  	int cnt = 0;
  	
    for (int i = x; i < s.size(); i += 4) {
    	if (s[i] == '!')
    		cnt++;
    	else
    		c = s[i];
    }
    
    m[c] += cnt;
  }
  
  cout << m['R'] << " " << m['B'] << " " << m['Y'] << " " << m['G'] << endl;
}