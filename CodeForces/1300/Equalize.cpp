#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string a, b;
	cin >> a >> b;
	
	int ans = 0;
	
	for(int i=1; i < n; i++) {
		if (a[i-1] != b[i-1] && a[i] != b[i] && a[i-1] == b[i] && a[i] == b[i-1])
			ans += 1, a[i-1] = b[i-1], a[i] = b[i];
	}
	
	for(int i=0; i < n; i++) {
		if (a[i] != b[i])
			ans += 1, a[i] = b[i];
	}
	
	cout << ans << endl;
}