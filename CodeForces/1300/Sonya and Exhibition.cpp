#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i < m; i++) {
		int li, ri;
		cin >> li >> ri;
	}
	
	string ans = string(n, '0');
	
	for(int i=0; i < n; i++) {
		if (i%2 == 0)
			ans[i] = '1';
	}
	
	cout << ans << endl;
}