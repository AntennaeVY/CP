#include<bits/stdc++.h>
using namespace std;

#define _USE_MATH_DEFINES

int main() {
	long double r, l;
	cin >> r >> l;
	
	if (l > 2*r) {
		cout << 0 << endl;
		return 0;
	}
	
	long double tetha = 2 * acos((l*l) / (-2*r*r) + 1);
	long double ans = tetha / (2 * M_PI);
	
	cout << fixed << setprecision(10) << abs(1 - ans) << endl;
}