#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a ) cin >> ai;
		
		int ans = 1;
		
		vector<bool> b(n);
		b[a[0]-1] = true;
		
		for(int i=1; i < n; i++) {
			bool can = false;
			
			if (a[i]-2 >= 0)
				can |= b[a[i]-2];
				
			if (a[i] < n)
				can |= b[a[i]];
				
			b[a[i]-1] = true;
				
			ans += can; 
		}
		
		cout << (ans == n ? "YES" : "NO") << endl;
	}
}