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
		
		int ans = 0, even = 0;
		
		for(auto ai:a) {
			even += (ai%2==0);
		}
		
		if (even != n)
			ans = even;
		
		cout << ans << endl;
	}
}