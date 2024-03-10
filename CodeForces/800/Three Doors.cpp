#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x;
		cin >> x;
		
		vector<int> a(3);
		for(auto &ai : a) cin >> ai;
		
		bool bad = false;
		
		for(int i=0; i < 3; i++) {
			bad |= a[i] == i+1;
		}
		
		bad |= a[x-1] == 0;
		
		cout << (bad ? "NO" : "YES") << endl;
	}
}