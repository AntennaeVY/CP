#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		cout << (a[0] == 1 ? "YES" : "NO") << endl;
	}
}