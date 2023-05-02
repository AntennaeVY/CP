#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int a, b, n, S;
		cin >> a >> b >> n >> S;
		
		int x = min(a, S/n);
		int y = min(b, S - x*n);
		
		if (x*n + y == S)	
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}