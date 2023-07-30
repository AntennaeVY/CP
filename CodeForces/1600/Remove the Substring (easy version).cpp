#include<bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	
	int ans = 0;

	for(int i=0; i < s.size(); i++) {
		for(int j=s.size()-1; j >= i; j--) {
			int x = 0;
			
			for(int k=0; k < s.size(); k++) {
				if (k >= i && k <= j)
					continue;
				
				if (x < t.size() && s[k] == t[x])
					x++;
			}
			
			if (x == t.size()) 
				ans = max(ans, j-i+1);
		}
	}
	
	cout << ans << endl;
}