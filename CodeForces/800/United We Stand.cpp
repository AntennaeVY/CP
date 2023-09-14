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
		
		sort(a.begin(), a.end());
		
		vector<int> b, c;
		
		for(int i=0; i < n; i++) {
			if (a[i] == a[0])
				b.push_back(a[i]);
			else
				c.push_back(a[i]);
		}
		
		if (c.empty()) {
			cout << -1 << endl;
			continue;
		}
		
		cout << b.size() << " " << c.size() << endl;
		for(auto &bi : b) cout << bi << " ";
		cout << endl;
		
		for(auto &ci : c) cout << ci << " ";
		cout << endl;
	}
	
}