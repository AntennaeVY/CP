#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
	
		long long s[2] = {0, 0};
		
		for(int i=0; i < n; i++) {
			s[i%2] += max(a[i], 0LL);
		}
		
		int x = *max_element(a.begin(), a.end());
		
		if (x < 0) 
			cout << x << endl;
		else
			cout << max(s[0], s[1]) << endl;
	}
}