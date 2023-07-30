#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> p(n);
		for(auto &pi:p) cin >> pi;
		
		int LIS = 1;
		
		for(int i=0; i < n; i++) {
			if (p[i] == LIS)
				LIS++;
		}
		
		cout << (n - LIS + k) / k << endl;
	}
}