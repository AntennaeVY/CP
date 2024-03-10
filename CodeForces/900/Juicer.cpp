#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, b, d;
	cin >> n >> b >> d;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	int ans = 0, amt = 0;
	
	for(int i=0; i < n; i++) {
		if (a[i] > b)
			continue;
			
		amt += a[i];
			
		if (amt > d) 
			ans++, amt = 0;
	}
	
	cout << ans << endl;
}