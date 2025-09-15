#include<bits/stdc++.h>
using namespace std;

long long f(long long x) {
	string sx = to_string(x);

	reverse(sx.begin(), sx.end());
	
	return stoll(sx);
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long x, y;
	cin >> x >> y;
	
	for(int i=3; i <= 10; i++) {
		long long r = f(x+y);
		x = y;
		y = r;
	}
	
	cout << y << "\n";
}