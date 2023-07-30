#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int n = s.size();
	
	int ans = 0;
	
	for(int i=0; i < n; i++) {
		if (s[i] != 'Q')
			continue;
			
		for(int j=i+1; j < n; j++) {
			if (s[j] != 'A')
				continue;
					
			for(int k=j+1; k < n; k++) {
				if (s[k] == 'Q')
					ans++;
			}	
		}
	}
	
	cout << ans << endl;
}