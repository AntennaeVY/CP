#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int m2=0, m3=0, n2=0, n3=0;
	
	while(n % 2 == 0)
		n2++, n/=2;
	
	while(n % 3 == 0)
		n3++, n/=3;
		
	while(m % 2 == 0)
		m2++, m/=2;
		
	while(m % 3 == 0)
		m3++, m/=3;
		
	if (n != m || n2 > m2 || n3 > m3) {
		cout << -1 << endl;
		return 0;
	}

	cout << m2 - n2 + m3 - n3 << endl;
}