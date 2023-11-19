#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		bool ok = false;
		
		vector<int> a(n);
		for(auto &ai : a) {
			cin >> ai;
			
			ok |= (ai == k);
		}
		
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}