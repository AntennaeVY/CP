#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	set<int> s(a.begin(), a.end());
	a.assign(s.begin(), s.end());
	
	if (a.size() == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	if (a.size() == 2) {
		if ((a[1] - a[0]) % 2)
			cout << a[1] - a[0] << endl;
		else
			cout << (a[1] - a[0])/2 << endl;
			
		return 0;
	}
	
	if (a.size() == 3) {
		if (a[2] - a[1] == a[1] - a[0]) {
			cout << a[1] - a[0] << endl;
			return 0;
		}
	}
	
	
	cout << -1 << endl;
}