#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;

	long long ans = 0;
	
	if (k == 1)
		ans = n;
	else
		ans = (1LL << __lg(n)) | ((1LL << __lg(n)) - 1);
	
	cout << ans << endl;
}