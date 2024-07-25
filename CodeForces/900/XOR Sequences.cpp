#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x, y;
		cin >> x >> y;
		
		int z = x ^ y, p = 0;
		
		while((z & 1) == 0) {
			p++;
			z >>= 1;
		}
		
		cout << (1LL << p) << endl;
	}
}