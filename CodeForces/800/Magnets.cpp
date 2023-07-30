#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<string> a(n);
	for(auto &ai:a) cin >> ai;

	int ans = 1;

	for(int i=1; i < n; i++) {
		if (a[i-1] != a[i])
			ans++;
	}
	
	cout << ans << endl;
}