#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int two = 0, three = 0;
		
		while(n%2 == 0) n/=2, two++;
		while(n%3 == 0) n/=3, three++;
		
		if (n != 1 || three < two) {
			cout << -1 << endl;
			continue;
		}
		
		cout << 2*three - two << endl;
	}
}