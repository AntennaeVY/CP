#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	
	vector<int> h(n);
	for(auto &hi : h) cin >> hi;
	
	int ans = 0;
	vector<int> turns_loss;
	
	for(int i=0; i < n; i++) {
		int p = h[i] / (a+b);
		int hr = h[i] - p*(a+b);
		
		if (hr == 0) 
			turns_loss.push_back((min(b, h[i])+a-1)/a);
		else if (hr > a)
			turns_loss.push_back((hr-1)/a);
		else
			ans++;		
	}
	
	sort(turns_loss.begin(), turns_loss.end());
	
	for(int i=0; i < turns_loss.size(); i++) {
		if (k < turns_loss[i])
			break;
		
		k -= turns_loss[i];
		ans++;
	}
	
	cout << ans << endl;
}