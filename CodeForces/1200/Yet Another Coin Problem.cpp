#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 1e9;
		
		for(int i=0; i <= 2; i++) {
			for(int j=0; j <= 1; j++) {
				for(int k=0; k <= 4; k++) {
					for(int l=0; l <= 2; l++) {
						if (n < i + j*3 + k*6 + l*10)
							continue;
						
						if ((n - (i + j*3 + k*6 + l*10)) % 15)
							continue;
							
						ans = min(ans, i + j + k + l + (n - (i + j*3 + k*6 + l*10))/15);
					}
				}
			}
		}
		
		cout << ans << endl;
	}
}