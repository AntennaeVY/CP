#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,l;
		cin >> a >> b >> l;
		
		set<int> s;
		
		long long x = 1;
		
		for(int i=0; i <= 20; i++) {
			if (x > l)
				break;
				
			long long y = 1;
				
			for(int j=0; j <= 20; j++) {
				if (y > l)
					break;
					
				if (l % (x*y) == 0)
					s.insert(l / (x*y));
					
				y *= b;
			}
				
			x *= a; 
		}
		// cout << *s.begin() << endl;
		cout << s.size() << "\n";
	}
}