#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<int, int> m;
	vector<int> g(n);

	for(int i=0; i < n; i++) {
		int hi;
		cin >> hi >> g[i];
		
		m[hi]++;
	}
	
	int ans = 0;
	
	for(int i=0; i < n; i++) {
		ans += m[g[i]];
	}
	
	cout << ans << endl;
}