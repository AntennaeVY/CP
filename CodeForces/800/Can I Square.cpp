#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		long long sum = 0;
		
		while(n--) {
			int x;
			cin >> x;
			
			sum += x;
		}
		
		if (sqrtl(sum) - (long long)sqrt(sum) > 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}