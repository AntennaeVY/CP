#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a > b)
			swap(a,b);
			
		int mid = b - (a - 1);
		int last = 2*(mid-1);
		
		int ans = (mid + c - 1) % last;
		
		if (ans == 0)
			ans = last;
			
		bool ok = true;
			
		if (a > last || b > last || c > last || ans > last)
			ok = false;
			
		if (ans == a || ans == b)
			ok = false;
			
		cout << (ok ? ans : -1) << endl;
	}
}