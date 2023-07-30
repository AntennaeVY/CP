#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	
	int n;
	cin >> n;
	
	set<int> a;
	vector<int> b(n);
	for(int i=1; i <= 2*n; i++) {
		a.insert(i);
	}
	
	for(int i=0; i < n; i++) {
		cin >> b[i];
		a.erase(b[i]);
	}
	
	int ans = 0;
	
	for(int i=0; i < n; i++) {
		auto it = a.upper_bound(b[i]);
		
		if (it != a.end()) {
			ans++;
			a.erase(it);
		}
	}
	
	cout << ans << endl;
}