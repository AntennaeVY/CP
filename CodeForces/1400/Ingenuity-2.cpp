#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    int x = 0, y = 0;

 	for(int i=0; i < n; i++) {
 		if (s[i] == 'N')
 			y++;
 		else if (s[i] == 'S')
 			y--;
 		else if (s[i] == 'E')
 			x++;
 		else
 			x--;
 	}
 	
 	if (x % 2 || y % 2 || x == 0 && y == 0 && s.size() == 2) {
 		cout << "NO" << endl;
 		continue;
 	}
 	
	vector<char> ans(n, 'H');
 	
 	if (x == 0 && y == 0) {
 		char ch;
 		
 		switch(s[0]) {
 			case 'N':
 				ch = 'S';
 				break;
 			case 'S':
 				ch = 'N';
 				break;
 			case 'E':
 				ch = 'W';
 				break;
 			case 'W':
 				ch = 'E';
 				break;
 		}
 		
 		ans[0] = ans[s.find(ch)] = 'R';
 	} else {
 		x /= 2, y /= 2;
 		int tx = 0, ty = 0;
 		
 		for(int i=0; i < n; i++) {
 			if (s[i] == 'N' && y > 0)
 				ans[i] = 'R', ty++, y--;
 			else if (s[i] == 'S' && y < 0)
 				ans[i] = 'R', ty--, y++;
 			else if (s[i] == 'E' && x > 0)
 				ans[i] = 'R', tx++, x--;
 			else if (s[i] == 'W' && x < 0)
 				ans[i] = 'R', tx--, x++;
 		}
 	}
 	
 	for(auto ch : ans)
 		cout << ch;
 	
 	cout << endl;
  }
}