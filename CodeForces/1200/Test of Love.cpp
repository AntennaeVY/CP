#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;
    
    s = 'L' + s + 'L', n += 2;

	int pos = 0;
	bool can = true;
	
	while(can && pos < n-1) {
		for(int i=pos+1; i < n; i++) {
			if (i - pos > m)
				break;
			
			if (s[i] == 'L')
				pos = i;
		}
		
		if (pos == n-1)
			break;
		
		for(int i=pos+m; i > pos; i--) {				
			if (s[i] == 'W') {
				pos = i;
				break;
			}
		}
		
		if (s[pos] != 'W') {
			can = false;
			break;
		}
		
		for(int i=pos+1; i < n; i++) {
			if (s[i] == 'C' || k == 0) {
				can = false;
				break;
			}
			
			pos++, k--;
			
			if (s[pos] == 'L')
				break;
		}
	}
	
	cout << (can ? "YES" : "NO") << endl;
	
  }
}