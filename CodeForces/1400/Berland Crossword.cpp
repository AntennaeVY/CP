#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
	
	bool ok = false;
	
	for(int i=0; i < 16; i++) {
		int u = U, r = R, l = L, d = D;
		
		int ul = i & 8;
		int ur = i & 4;
		int dr = i & 2;
		int dl = i & 1;
		
		if (ul != 0) {
			u -= 1;
			l -= 1;
		}
		
		if (ur != 0) {
			u -= 1;
			r -= 1;
		}
		
		if (dr != 0) {
			d -= 1;
			r -= 1;
		}
		
		if (dl != 0) {
			d -= 1;
			l -= 1;
		}

		if (u > (n-2) || u < 0)
			continue;
		
		if (d > (n-2) || d < 0) 
			continue;
			
		if (l > (n-2) || l < 0)
			continue;
			
		if (r > (n-2) || r < 0)
			continue;
			
	  	ok = true;
	}
	
	cout << (ok ? "YES" : "NO") << endl;
  }
}