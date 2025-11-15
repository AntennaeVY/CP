#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int p;
	cin >> p;
	
	int ans = 0;
	
	while(p--) {
		int n;
		cin >> n;
		
		ans += n % 2;
	}
	
	cout << ans << "\n";
}