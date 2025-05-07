#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), b(m);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	
	long long sum = 0;
	int x = 0;
	
	while(x < n && a[x] >= 0) {
		sum += a[x], x++;
	}
	
	int y = 0;
	while (y < m && y < x && b[y] >= 0) {
		sum += b[y], y++;
	}
	
	long long mx = sum;

	while(x < n && y < m && b[y] >= 0) {
		sum += a[x] + b[y], x++, y++;
		mx = max(sum, mx);
	}
	
	cout << mx << endl;
}