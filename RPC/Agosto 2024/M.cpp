#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, w;
	cin >> n >> w;
	
	vector<int> h(n);
	for(auto &hi : h) cin >> hi;
	
	sort(h.begin(), h.end());
	
	bool can = true;
	
	for(int i=w; i < n; i++) {
		can &= h[i] > h[i-w];
	}
	
	if (can)
		cout << "yes\n\n";
	else
		cout << "no\n\n";
}