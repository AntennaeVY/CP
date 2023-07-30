#include<bits/stdc++.h>
using namespace std;

int main() {
	long long a,b, ans = 0;
	cin >> a >> b;
	
	if (a==b) {
		cout << 1 << endl;
		return 0;
	}
	
	if (b-a >= 10) {
		cout << 0 << endl;
		return 0;
	}
	
	ans = b%10;
	
	for(long long i = 1; i < (b-a); i++) {
		ans = (ans * (b-i)%10)%10;
	}
	
	cout << ans << endl;
}