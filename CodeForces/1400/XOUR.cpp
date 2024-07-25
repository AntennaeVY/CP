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
		
		map<int, vector<int>> m;
		
		for(int i=0; i < n; i++) {
			int mi = (a[i] >> 2);
			m[mi].push_back(a[i]);
		}
		
		for(auto &[mi, v] : m) {
			sort(v.rbegin(), v.rend());
		}
		
		for(int i=0; i < n; i++) {
			int mi = (a[i] >> 2);
			
			cout << m[mi].back() << " ";
			
			m[mi].pop_back();
		}
		
		cout << "\n";
	}
}