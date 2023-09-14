#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	int target = 240 - k, accum = 0, ans = 0;
	
	for(int i=1; i <= n; i++) {
		if (accum + 5*i <= target)
			ans = i;
			
		accum += 5*i;
	} 
	
	cout << ans << endl;
}