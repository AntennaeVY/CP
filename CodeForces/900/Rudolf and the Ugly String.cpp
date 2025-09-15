#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int ans = 0;
		
		for(int i=0; i <= n-3; i++) {
			string str = s.substr(i, 3);
			string str2 = s.substr(i, 5);
			
			if (str2 == "mapie") {
				ans++;
				i += 2;
				continue;
			}
			
			if ( str == "map" || str == "pie")
				ans++;
		}
		
		cout << ans << "\n";
	}
}