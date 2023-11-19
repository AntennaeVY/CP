#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	sort(a.begin(), a.end());
	
	int ans = 0, cnt = 0;
	
	for(auto x : a)
		if (x < 0 && cnt < m)
			ans += abs(x), cnt++;
			
	cout << ans << endl;
}