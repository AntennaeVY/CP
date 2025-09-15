#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n;
	cin >> n;
	
	long long c = 0, p = 0;
	
	for(long long i=2; i*i <= n; i++) {
		if (n % i == 0) c++, p = i;
		while(n % i == 0) n /= i;
	}	
	
	if (n != 1)
		c++, p = n;
	
	cout << (c == 1 ? p : 1) << "\n";
}