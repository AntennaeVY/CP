#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		long long n;
		cin >> n;

		long long ans = 0;

		while(n) {
			ans += n;
			n/=2;
		}

		cout << ans << endl;
	}
}