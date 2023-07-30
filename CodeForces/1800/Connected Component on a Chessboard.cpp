#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int b, w;
		cin >> b >> w;
		
		if (min(b, w) + 2*min(b, w) + 1 < max(b,w)) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		
		for(int i=2; i <= 2*min(b, w) + 1; i++) {
			if (w >= b)
				cout << 2 << " " << i << endl; 
			else
				cout << 2 << " " << i-1 << endl;
		}
		
		int cnt = max(b,w) - min(b,w);
		
		for(int i=3; i <= 2*min(b, w) + 1; i+=2, cnt-=2) {
			if (cnt < 2)
				break;
			
			if (w >= b) {
				cout << 1 << " " << i << endl;
				cout << 3 << " " << i << endl;
 			} else {
				cout << 1 << " " << i-1 << endl;
				cout << 3 << " " << i-1 << endl;
 			}
		}
		
		if (!cnt)
			continue;
		
		if (w >= b)
			cout << 2 << " " << 2*min(b, w) + 2 << endl;
		else 
			cout << 2 << " " << 2*min(b,w) + 1 << endl;
	}
}