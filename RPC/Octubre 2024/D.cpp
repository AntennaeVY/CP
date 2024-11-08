#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	
	int cnt = (1 << n) - r, ans = 1;
	
	if (r == 1) {
		cout << n << endl;
		return 0;
	}
	
	if (cnt == 0) {
		cout << 1 << endl;
		return 0;
	}
	
	while(cnt) {
		cnt -= 1, cnt /= 2;
		
		ans++;
	}
	
	cout << ans << endl;
}