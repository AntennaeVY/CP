#include<bits/stdc++.h>
using namespace std;

int main() {
	long long c2, c3, c5, c6;
	cin >> c2 >> c3 >> c5 >> c6;
	
	long long ans = 256 * min(c2, min(c5, c6));
	
	c2 -= ans / 256;
	ans += min(c2, c3) * 32;
	
	cout << ans << endl; 
}