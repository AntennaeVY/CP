#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		a.push_back(0);
		
		int cnt=0, ans = a[0];
		
		for(int i=1; i <= n; i++) {
			if (a[i] == 0)
				ans += cnt/3, cnt = 0;
			else
				cnt++;
		}
		
		cout << ans << endl;
	}
}