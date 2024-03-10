#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	
	int ans;
	
	if (l == 1 && r == n) 
		ans = 0;
	else if (l == 1)
		ans = abs(r-pos) + 1;
	else if (r == n)
		ans = abs(l-pos) + 1;
	else
		ans = min(abs(r-pos), abs(l-pos)) + r-l + 2;
	
	cout << ans << endl;
}