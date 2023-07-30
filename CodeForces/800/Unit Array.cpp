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
		
		int ans = 0;
		
		int m = count(a.begin(), a.end(), -1);
		
		cout << max(m - n/2, 0) + min(m, n/2) % 2 << endl;
	}
}