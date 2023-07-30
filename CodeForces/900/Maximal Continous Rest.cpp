#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	a.insert(a.end(), a.begin(), a.end());
	
	int cnt = 0, ans = 0;
	
	for(int i=0; i < 2*n; i++) {
		if (a[i] == 1)
			cnt++;
		else
			cnt = 0;
		
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;
}