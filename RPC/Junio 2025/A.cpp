#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<int> mn(n, 1e9), mx(n, 0);
	
	mx[0] = a[0];
	mn[n-1] = a[n-1];
	
	for(int i=1; i < n; i++)
		mx[i] = max(a[i], mx[i-1]);
		
	for(int i=n-2; i >= 0; i--) 
		mn[i] = min(a[i], mn[i+1]);
		
	vector<int> ans;
	
	for(int i=0; i < n; i++) {
		if (mx[i] <= a[i] && mn[i] >= a[i])
			ans.push_back(a[i]);
	}
	
	int m = ans.size();
	
	cout << m;
	
	if (m)
		cout << " ";
	
	for(int i=0; i < min(100, m); i++) {
		cout << ans[i];
		
		if (i < min(100, m) - 1)
			cout << " ";
	}
	
	cout << '\n';
}