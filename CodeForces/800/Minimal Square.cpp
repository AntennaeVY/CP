#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		
		if (a > b)
			swap(a,b);
			
		if (2*a < b)
			cout << b*b << endl;
		else
			cout << 4*a*a << endl;
	}
}