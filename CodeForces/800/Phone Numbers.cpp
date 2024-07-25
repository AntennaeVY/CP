#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int ans = 0, cnt = 0;
	
	for(auto c : s)
		cnt += (c == '8');
		
	for(int i=1; i <= cnt; i++) {
		if ((n - i) / 10 >= i)
			ans = i;
	}
	
	cout << ans << endl;
}