#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		string match = "2020", search = "";
		bool ok = false;
		
		
		for(int i=1; i <= 4; i++) {
			search += match[i-1];
			
			for(int j=0; j < n; j++) {
				if (s.substr(j, i) != search)
					continue;
					
				for(int k=j+i; k < n; k++) {
					if (s.substr(k, 4-i) == match.substr(i)) {
						if ((j == 0 || k + 4-i == n) && k-j == 1)
							ok = true;
							
						ok |= (k+4-i-j == n);
					}
				}
			}
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}