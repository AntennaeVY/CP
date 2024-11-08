#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;

		int cnt = k / 2;
		
		if (k % 2)
			cnt += n % 2;
		
		if (cnt % 2 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}