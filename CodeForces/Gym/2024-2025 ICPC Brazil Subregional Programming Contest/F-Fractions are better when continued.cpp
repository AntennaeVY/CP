#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n+1), b(n+1);
	a[0] = 1, b[0] = 1;
	
	for(int i=1; i <= n; i++) {
		a[i] = b[i-1];
		b[i] = a[i-1] + b[i-1];
	}
	
	cout << a[n] << endl;
}