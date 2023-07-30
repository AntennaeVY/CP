#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int ans = 0;
	int mn = 10001, mx = -1;
	
	for(int i=0; i < n; i++) {
		int x; 
		cin >> x;
		
		if (x < mn && mn != 10001)
			ans++;
			
		if (x > mx && mx != -1)
			ans++;
			
		mx = max(x, mx);
		mn = min(x, mn);
	}
	
	cout << ans << endl;
}