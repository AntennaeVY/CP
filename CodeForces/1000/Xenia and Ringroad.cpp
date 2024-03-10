#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(m);
	for(auto &ai : a) cin >> ai;
	
	long long ans = a[0] - 1;
	
	for(int i=1; i < m; i++) {
		ans += a[i] - a[i-1];
		
		if (a[i] - a[i-1] < 0)
			ans += n;
	}
	
	cout << ans << endl;
}