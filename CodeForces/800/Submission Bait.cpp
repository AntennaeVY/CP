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
		
		map<int, int> m;
		
		for(int i=0; i < n; i++) {
			m[a[i]]++;
		}
		
		int cnt = 0;
		
		for(auto [x, y] : m) {
			cnt += y % 2;
		}
		
		if (cnt > 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
}