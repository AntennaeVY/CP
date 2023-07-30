#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		if (count(a.begin(), a.end(), 0) == n) {
			cout << "NO" << endl; 
		} else {
			cout << "YES" << endl;
		}
	}
}