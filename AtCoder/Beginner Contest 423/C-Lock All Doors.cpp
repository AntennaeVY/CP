#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	vector<int> l(n);
	for (int i = 0; i < n; i++) cin >> l[i];
	int x = n, y = 0;
	for (int i = 0; i < n; i++) {
		if (l[i] == 0) {
			x = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (l[i] == 0) {
			y = i;
			break;
		}
	}
	int open = count(l.begin(), l.end(), 0);
	int t = 0;
	if (x <= r - 1) for (int i = x + 1; i < r; i++) if (l[i] == 1) t++;
	if (y >= r) for (int i = r; i < y; i++) if (l[i] == 1) t++;
	int ans = 2 * t + open;
	cout << ans << '\n';
}
