#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int sum = 0, ans = 0;
		
		for(int x=2; x <= n; x++) {
			int curr = x * (n/x) * (n/x + 1) / 2;
			
			if (curr >= sum)
				sum = curr, ans = x;
		}
		
		cout << ans << endl;
	}
}