#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int l, r;
		cin >> l >> r;
		
		int a = 0, b = 0, c = 0;
		
		for(int i=30; i >= 0; i--) {
			int bit = (1 << i);
			
			if ((l & bit) == (r & bit)) {
				if ((r & bit))
					a |= bit;
					
				continue;
			}
				
			a |= bit;
			b = a-1;
			
			for(int j=r; j >= r-2; j--)
				if (j != a && j != b)
					c = j;
					
			break;
		}
		
		cout << a << " " << b << " " << c << endl;
	}
}