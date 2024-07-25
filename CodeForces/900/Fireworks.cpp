#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long a,b,m;
		cin >> a >> b >> m;
		
		long long cnt_a = m / a;
		long long cnt_b = m / b;
		
		cout << cnt_a + cnt_b + 2 << endl;
	}
}