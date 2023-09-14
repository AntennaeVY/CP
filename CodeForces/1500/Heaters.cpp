#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<int> h(n, -1);
	
	if (a[0])
		h[0] = 0;
		
	for(int i=1; i < n; i++) {
		if (a[i])
			h[i] = i;
		else
			h[i] = h[i-1];
	}
	
	int x = -1, ans = 0;
	
	while(x < n-1) {
		int left = max(-1, x-r+1);
		int right = min(n-1, x+r);
		int curr = max(h[left+1], h[right]);
		
		if (curr == left) {
			ans = -1;
			break;
		}
		
		x = curr+r-1;
		ans++;
	}
	
	cout << ans << endl;
}