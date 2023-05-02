#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<bool> l(n, false);
	
	int p;
	cin >> p;
	
	for(int i=0; i < p; i++) {
		int x;
		cin >> x;
		
		l[x-1] = true;
	}
	
	int q;
	cin >> q;
	
	for(int i=0; i < q; i++) {
		int x;
		cin >> x;
		
		l[x-1] = true;
	}
	
	bool ok = true;
	for(auto x : l) {
		ok &= x;
	}
	
	cout << (ok ? "I become the guy." : "Oh, my keyboard!") << endl;
}