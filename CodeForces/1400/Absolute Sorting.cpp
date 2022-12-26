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
		
		int at_least = 0, at_most = INT_MAX;
		
		for(int i=1; i < n; i++) {
			if (a[i-1] > a[i])
				at_least = max(at_least, (a[i-1]+a[i]+1)/2);
			else if (a[i-1] < a[i])
				at_most = min(at_most, (a[i-1]+a[i])/2);
		}
		
		cout << (at_least > at_most ? -1 : at_least) << endl;
	}
}