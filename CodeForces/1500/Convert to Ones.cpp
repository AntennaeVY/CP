#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, x, y;
	cin >> n >> x >> y;
	
	string s;
	cin >> s;
	
	int cnt = 0, z = 0;
	
	for(int i=0; i < n; i++) {
		z += s[i] == '0';
		
		if (s[i] == '1')
			cnt += z != 0, z = 0;
	}
	
	cnt += z != 0;
	
	long long ans = cnt * y;
	
	for(int i=1; i < cnt; i++) {
		ans = min(ans, i*x + (cnt-i)*y);
	}
	
	cout << ans << endl;
}