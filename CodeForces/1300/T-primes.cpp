#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
	if (x == 2)
		return true;
	
	if (x % 2 == 0 || x == 1)
		return false;
		
	for(int i=3; i*i <= x; i+=2) {
		if (x % i == 0)
			return false;
	}
	
	return true;
}
 
int main() {
	int n;
	cin >> n;
	
	while(n--) {
		long long x;
		cin >> x;
		
		double sq1 = sqrtl(x);
		int sq2 = (int)sq1;
		
		if (sq1 - sq2 > 0) {
			cout << "NO" << endl;
		} else {
			cout << (isPrime(sq2) ? "YES" : "NO") << endl;
		}
		
	}
}