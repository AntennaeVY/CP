#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> ans(n);
		ans[0] = 1, ans[n-1] = 2;
		for(int i=1; i < n-1; i++) {
			ans[i] = 2+i;
		}
		
		for(auto &ansi : ans)
			cout << ansi << " ";
		cout << "\n";
	}
}