#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		
		int x = n-1;
		int rem = 0;
		
		for(x=n-1; x >= 0; x--) {
			if (s[x] != '0')
				break;
				
			rem++;
		}
		
		for(int i=0; i < x; i++) {
			if (s[i] != '0')
				rem++;
		}
		
		cout << rem << endl;
	}
}