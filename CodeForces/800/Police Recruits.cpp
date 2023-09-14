#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int p = 0, ans = 0;
	while(n--) {
		int x;
		cin >> x;
		
		if (x >= 0)
			p += x;
		else
			ans += (p == 0), p -= min(p, 1);
	}
	
	cout << ans << endl;
}