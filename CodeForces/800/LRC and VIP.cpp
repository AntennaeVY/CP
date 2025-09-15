#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		if (count(a.begin(), a.end(), a[0]) == n) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		
		int mx = *max_element(a.begin(), a.end());
		
		for(int i=0; i < n; i++) {
			if (a[i] == mx)
				cout << 2 << " ";
			else
				cout << 1 << " ";
		}
		
		cout << endl;
	}
}