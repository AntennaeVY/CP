#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	if (n == 1) {
		cout << 1 << " " << 1 << endl;
		cout << -a[0] << endl;
		
		for(int i=0; i < 2; i++){
			cout << 1 << " " << 1 << endl;
			cout << 0 << endl;
		}
		
		return 0;
	}
	
	cout << 1 << " " << n << endl;
	
	for(int i=0; i < n; i++) {
		cout << -1LL * a[i] * n << " ";
	}
	
	cout << endl;
	cout << 2 << " " << n << endl;
	
	for(int i=1; i < n; i++) {
		cout << 1LL * a[i] * (n-1) << " ";
	}
	
	cout << endl;
	cout << 1 << " " << 1 << endl;
	
	cout << 1LL * a[0] * (n-1) << endl;
}