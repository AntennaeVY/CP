#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n, x, y;
		cin >> n >> x >> y;
		
		long long ans = 0;
		
		long long lcm = (x*y)/__gcd(x, y);
		long long mult_x_cnt = n/x;
		long long mult_y_cnt = n/y;
		long long mult_lcm_cnt = n/lcm;
		
		long long add = n*(n+1)/2 - (n - mult_x_cnt + mult_lcm_cnt) * (n - mult_x_cnt + mult_lcm_cnt + 1) / 2;
		long long rem = (mult_y_cnt - mult_lcm_cnt) * (mult_y_cnt - mult_lcm_cnt + 1) / 2;
		
		cout << add - rem << endl;
	}
}