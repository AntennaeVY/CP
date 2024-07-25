#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int k, q;
		cin >> k >> q;
		
		vector<int> a(k);
		for(auto &ai : a) cin >> ai;
		
		while(q--) {
			int n;
			cin >> n;
			
			cout << min(n, a[0] - 1) << " ";
		}
		
		cout << endl;
	}
}