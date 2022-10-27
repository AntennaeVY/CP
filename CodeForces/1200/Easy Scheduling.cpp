#include<bits/stdc++.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	cin >> t;
	
	while(t--) {
		int h,p;
		cin >> h >> p;
		
		long long ans = 0;
		int x = __lg(p) + 1;
		x = min(h, x);
		
		long long remaining = (1LL << h) - (1LL << x);
		long long used = remaining/p;
		
		ans += x;
		ans += max(0LL, used);
		ans += !!(max(0LL, remaining - used*p));
		
		cout << ans << "\n";
	}
}