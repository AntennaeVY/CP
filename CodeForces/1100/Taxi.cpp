#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(4, 0);
	
	while(n--) {
		int x;
		cin >> x;
		
		a[--x]++;
	}
	
	int ans = a.back();
	
	ans += a[1]/2, a[1] %= 2;
	
	int m = min(a[0], a[2]);
		
	ans += m, a[0] -= m, a[2] -= m;

	if (a[1])
		ans += 1, a[0] = max(a[0] - 2, 0);
		
	ans += a[0] / 4 + (a[0] % 4 != 0) + a[2];
	
	cout << ans << endl;
}