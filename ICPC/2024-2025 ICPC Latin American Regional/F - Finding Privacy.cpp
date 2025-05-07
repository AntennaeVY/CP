#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k, n;
	cin >> k >> n;
	
	if (k < (n+2)/3 || k > (n+1)/2) {
		cout << '*' << '\n';
		return 0;
	}	
	
	int N = n;
	string ans = "";
	
	while(k) {
		if (n % 3 == 0 && k == (n+2)/3) {
			ans += "-X-";
			n -= 3, k -= 1;
		} else {
			ans += "X-";
			n -= 2, k -= 1;
		}
	}
	
	cout << ans.substr(0, N) << '\n';
}