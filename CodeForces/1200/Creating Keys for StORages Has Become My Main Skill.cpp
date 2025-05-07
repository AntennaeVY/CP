#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		int result = 0;
		vector<int> ans;
		
		for(int i=0; i < n-1; i++) {
			if ((~x & i) == 0) {
				ans.push_back(i);
				result |= i;
			}
		}
		
		if ((result | (n-1)) == x) {
			ans.push_back(n-1);
		} else {
			ans.push_back(x);
		}
		
		while(ans.size() < n)
			ans.push_back(0);
		
		for(auto &ai : ans)
			cout << ai << " ";
		cout << '\n';
	}
}