#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, n;
		cin >> a >> b >> n;
		
		if (b > a)
			swap(a,b);
			
		int ans = 0;
			
		while(a <= n && b <= n) {
			b += a;
			ans++;
			
			if (b > n)
				break;
				
			a += b;
			ans++;
		}
		
		cout << ans << endl;
	}
}