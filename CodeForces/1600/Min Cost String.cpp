#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	string ans = "";
	for(int i=0; i < k; i++) {
		ans += ('a' + i);
		
		for(int j=i+1; j < k; j++) {
			ans += ('a' + i);
			ans += ('a' + j);
		}
	}
	
	for(int i=0; i < n; i++) {
		cout << ans[i % ans.size()];
	}
}