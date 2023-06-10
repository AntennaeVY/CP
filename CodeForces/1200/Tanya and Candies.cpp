#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int total_even = 0, total_odd = 0;
	for(int i=0; i < n; i++) {
		if ((i+1) & 1)
			total_odd += a[i];
		else
			total_even += a[i];
	}
	
	int ans = 0;
	
	int current_odd = 0, current_even = 0;
	for(int i=0; i < n; i++) {
		if ((i+1) & 1)
			total_odd -= a[i];
		else
			total_even -= a[i];
			
		ans += (current_odd + total_even == current_even + total_odd);
			
		if ((i+1) & 1)
			current_odd += a[i];
		else
			current_even += a[i];
	}
	
	cout << ans << endl;
}