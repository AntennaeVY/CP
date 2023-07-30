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
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			map<char, int> m;
			int maxima = 0;
			
			for(int j=i; j < n; j++) {
				if (j-i+1 > 100)
					break;
				
				m[s[j]]++;
				maxima = max(maxima, m[s[j]]);
				
				if (m.size() >= maxima)
					ans++;
			}
		}
		
		cout << ans << endl;
	}
}