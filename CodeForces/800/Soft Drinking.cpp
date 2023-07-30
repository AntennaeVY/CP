#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	
	int mn_l = (k*l) / nl;
	int mn_p = p / np;
	
	cout << min(c*d, min(mn_l, mn_p))/n << endl;
}