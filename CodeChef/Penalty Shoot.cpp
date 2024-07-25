#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int x, y;
	    cin >> x >> y;
	    
	    if (y > x && y - x > 2) {
	        cout << "NO" << endl;
	        continue;
	    }
	        
	    if (x > y && x - y > 1) {
	        cout << "NO" << endl;
	        continue;
	    }
	   
	   cout << "YES" << endl;
	}

}
