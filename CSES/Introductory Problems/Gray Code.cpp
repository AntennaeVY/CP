#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<string> ans = {"0", "1"};
	
	while(ans.size() < (1 << n)) {
		int m = ans.size();
		int k = ans[m-1].size();
		
		for(int i=m-1; i >= 0; i--) {
			string zeros(k - ans[i].size(), '0');
			ans.push_back("1" + zeros + ans[i]);
		}
	}
	
	for(int i=0; i < (1 << n); i++) {
		string zeros(n-ans[i].size(), '0');
		cout << zeros << ans[i] << "\n";
	}
}