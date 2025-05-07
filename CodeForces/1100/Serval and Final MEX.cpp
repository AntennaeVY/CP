#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int cnt = count(a.begin(), a.end(), 0);
		
		if (!cnt) {
			cout << "1\n";
			cout << "1 " << n << "\n";
			continue;
		}
		
		if (a[0] != 0) {
			cout << "2\n";
			cout << "2 " << n << "\n";
			cout << "1 2" << "\n";
			continue;
		}
		
		if (a[n-1] != 0) {
			cout << "2\n";
			cout << "1 " << n-1 << "\n";
			cout << "1 2" << "\n";
			continue;
		}
		
		cout << "3\n";
		cout << "1 " << n-2 << "\n";
		cout << "2 3\n";
		cout << "1 2\n";
	}
}