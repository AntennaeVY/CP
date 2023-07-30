#include<bits/stdc++.h>
using namespace std;

long long _gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);
		
	if (b == 0)
		return a;
		
	return _gcd(b, a%b);
}

int main() {
	long long n,m,q;
	cin >> n >> m >> q;
	
	long long gcd = _gcd(n, m);
	
	while(q--) {
		long long sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		
		sy--, ey--;
		
		sy /= (sx == 1 ? n/gcd : m/gcd);
		ey /= (ex == 1 ? n/gcd : m/gcd);
		
		cout << (sy == ey ? "YES" : "NO") << '\n';
	}
}