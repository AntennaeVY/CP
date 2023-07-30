#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
			
		set<long long> s;
		long long x = 2, ans = 1;
		
		while(x*x <= n) {
			if (!s.count(x*x))
				ans++;
	
			if (!s.count(x*x*x) && x*x*x <= n)
				ans++;
				
			s.insert(x*x);
			s.insert(x*x*x);
				
			x++;
		}
		
		cout << ans << endl;
	}
}