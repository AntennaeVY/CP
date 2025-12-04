#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int ans = 0;
	
	long long p = 5;
	while(p <= n)
		ans += n / p, p*=5;
	
	cout << ans << endl;
}