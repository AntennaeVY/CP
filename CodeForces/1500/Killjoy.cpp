#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		int cnt = count(a.begin(), a.end(), x);
		int sum = accumulate(a.begin(), a.end(), 0);
		
		if (cnt == n) {
			cout << 0 << endl;
		} else if (sum == x*n || cnt != 0) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
}