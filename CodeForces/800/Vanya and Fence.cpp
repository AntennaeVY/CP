#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	
	int ans = 0;
	
	for(int i=0; i < n; i++) {
		int x;
		cin >> x;
		
		ans += x > h ? 2 : 1;
	}
	
	cout << ans << endl;
}