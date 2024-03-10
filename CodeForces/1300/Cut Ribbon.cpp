#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	
	int ans = 0;
	
	for(int i=0; i*a <= n; i++) {
		for(int j=0; i*a + j*b <= n; j++) {
			int k = n - i*a - j*b;
			
			if (k % c == 0)
				ans = max(ans, i + j + k / c);
		}
	}
	
	cout << ans << endl;
}