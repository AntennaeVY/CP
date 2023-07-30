#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	
	int ans = 0;
	
	ans = max(ans, a+b+c);
	ans = max(ans, a*b*c);
	ans = max(ans, (a+b)*c);
	ans = max(ans, a+b*c);
	ans = max(ans, a*b+c);
	ans = max(ans, a*(b+c));
	
	cout << ans << endl;
}
