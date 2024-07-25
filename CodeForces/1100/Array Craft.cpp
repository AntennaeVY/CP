#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x, y;
		cin >> n >> x >> y;
		
		x--, y--;
		
		vector<int> v(n);
		for(int i=y; i <= x; i++) {
			v[i] = 1;
		}
		
		int val = -1;
		
		for(int i=y-1; i >= 0; i--) {
			v[i] = val;
			val = -val;
		}
		
		val = -1;
		
		for(int i=x+1; i < n; i++) {
			v[i] = val;
			val = -val;
		}
		
		for(auto &vi : v)
			cout << vi << endl;
	}
}