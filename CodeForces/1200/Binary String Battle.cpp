#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int cnt = 0;
		for(auto &si : s) cnt += si == '1';
		
		cout << (cnt > k && n >= 2*k ? "Bob" : "Alice" ) << "\n"; 
	}
}