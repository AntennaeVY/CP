#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<pair<int,int>> ans;
		int B = 1, N = 3*n;
		
		while(B < N) {
			ans.push_back({B, N});
			
			B += 3;
			N -= 3;
		}
		
		cout << ans.size() << endl;
		for (auto x : ans) {
			cout << x.first << " " << x.second << endl;
		}
	}
}