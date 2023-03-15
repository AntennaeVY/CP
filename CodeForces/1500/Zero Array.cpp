#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int mx = 0;
	long long sum = 0;
	vector<int> a(n);
	
	for(int i=0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		
		mx = max(mx, a[i]);
	}

	if (mx <= sum-mx && sum%2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}