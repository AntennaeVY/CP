#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int mn = INT_MAX;
		
		vector<int> a(n);
		for(auto &ai:a) {
			cin >> ai;
			mn = min(ai, mn);
		}
		
		cout << (a[0] == mn ? "Bob" : "Alice") << endl;
	}
}