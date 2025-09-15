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
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		int sum = 0;
		for(int i=0; i < n; i++) {
			if (a[i] > b[i])
				sum += a[i] - b[i];
		}
		
		cout << sum + 1 << "\n";
	}
}