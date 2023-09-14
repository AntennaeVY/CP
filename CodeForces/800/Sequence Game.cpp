#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b;
		for(auto &ai : a) cin >> ai;
		
		for(int i=0; i < n; i++) {
			b.push_back(a[i]);
		
			if (a[i] != 1)	
				b.push_back(1);
		}
		cout << b.size() << endl;
		for(auto &bi : b) cout << bi << " ";
		cout << endl;
	}
}