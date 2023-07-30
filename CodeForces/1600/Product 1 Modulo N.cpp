#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<bool> can(n, true);
	
	for(int i=2; i < n; i++) {
		if (n % i)
			continue;
			
		for(int j=1; i*j < n; j++) {
			can[i*j] = false;
		}
	}
	
	long long mult = 1;
	
	for(int i=2; i < n; i++) {
		if (can[i])
			mult = ((mult % n) * i) % n;
	}
	
	if (mult != 1)
		can[mult] = false;
		
	int ans = accumulate(can.begin(), can.end(), -1);
	
	cout << ans << endl;
		
	for(int i=1; i < n; i++) {
		if (can[i])
			cout << i << " ";
	}
	
	cout << endl;
}