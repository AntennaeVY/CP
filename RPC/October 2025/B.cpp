#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int d;
	cin >> d;
	
	long double a, o;
	cin >> a >> o;
	
	long double dx, dy;
	cin >> dx >> dy;
	
	long double zero = 0;
	
	long double alcohol = max(a - dx*d, zero);
	long double total = max(a - dx*d, zero) + max(o - dy*d, zero);

	
	cout << fixed << setprecision(8) << ((alcohol / total) * 100 )<< "\n";
}