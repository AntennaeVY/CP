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
		
		map<int, pair<int, int>> m;
		
		for(int i=0; i < n; i++) {
			m[a[i]].first++, m[a[i]].second = i+1;
		}
		
		for(auto [x, y] : m) {
			if (y.first == 1)
				cout << y.second << endl;
		}
	}
}