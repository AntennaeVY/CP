#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		if (n % 2 == 0) {
			cout << -1 << endl;
			continue;
		}
		
		vector<int> ans(n, -1);
		
		ans[n/2] = 1;
		
		int cnt = 2;
		for(int i=n/2 + 1; i < n; i++) {
			ans[i] = cnt++; 
		}
		
		for(int i=n/2 - 1; i >= 0; i--) {
			ans[i] = cnt++;
		}
		
		for(auto c : ans)
			cout << c << " "; 
			
		cout << endl;
	}
}