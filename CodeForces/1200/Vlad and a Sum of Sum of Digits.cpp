#include<bits/stdc++.h>
using namespace std;

int ans[200'000];


int main() {
	ans[0] = 0;
	
	for(int i=1; i <= 2e5; i++) {
		int x = i, sum = 0;
		
		while(x) {
			sum += x % 10;
			x /= 10;
		}
		
		ans[i] = ans[i-1] + sum;
		
	}
	
	int t;
	cin >> t;
	 
	while(t--) {
		int n;
		cin >> n;
		
		cout << ans[n] << endl;
	}
}