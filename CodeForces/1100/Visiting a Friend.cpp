#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), b(n);
	
	for(int i{}; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	bool ok = true;	
	int end = b[0];
	
	for(int i=1; i < n; i++) {
		if (a[i] > end)
			ok = false;
		
		end = max(end, b[i]);
	}
	
	if (a[0] != 0 || m > end)
		ok = false;
	
	cout << (ok ? "YES" : "NO") << endl; 
}