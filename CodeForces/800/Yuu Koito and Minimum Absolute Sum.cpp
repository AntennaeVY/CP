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
		
		if (a[0] == -1 && a[n-1] == -1) {
			a[0] = a[n-1] = 0;
		} else if (a[0] == -1) {
			a[0] = a[n-1];
		} else if (a[n-1] == -1) {
			a[n-1] = a[0];
		}
		
		for(int i=0; i < n; i++) {
			if (a[i] == -1)
				a[i] = 0;
		}
		
		cout << abs(a[n-1] - a[0]) << "\n";
		
		for(auto &ai : a)
			cout << ai << " ";
		cout << "\n";
	}
}