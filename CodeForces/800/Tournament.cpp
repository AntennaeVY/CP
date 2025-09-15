#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, j, k;
		cin >> n >> j >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		if (k >= 2) {
			cout << "YES\n";
		} else {
			cout << ( *max_element(a.begin(), a.end()) == a[j-1]? "YES\n" : "NO\n");
		}
	}
}