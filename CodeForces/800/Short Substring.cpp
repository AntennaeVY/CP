#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string b;
		cin >> b;
		
		int n = b.size();
		
		string ans = b.substr(0, 2);
		
		for(int i=3; i < n; i+=2) {
			ans += b[i];
		}
		
		cout << ans << endl;
	}
}