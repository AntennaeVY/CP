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
		
		if (n > 2) {
			cout << "NO" << endl;
			continue;
		}
		
		if (a[1] - a[0] > 1) {
			cout << "YES" << endl;
		} else 
			cout << "NO" << endl;
	}
}