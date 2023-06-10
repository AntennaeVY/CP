#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	
	string s;
	cin >> s;
	
	reverse(s.begin(), s.end());
	
	int ans = 0;
	
	for(int i=0; i < y; i++) {
		ans += (s[i] != '0');
	}

	for(int i=y+1; i < x; i++) {
		ans += (s[i] != '0');
	}
	
	ans += (s[y] != '1');
	
	cout << ans << endl;
}