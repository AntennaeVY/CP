#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> d(n);
	for(auto &di : d) cin >> di;
	
	int odd = 0, even = 0;
	array<int, 9> c({});
	
	for(int i=0; i < n; i++) {
		c[d[i]] += 1;
		
		odd += (d[i] % 2);
		even += !(d[i] % 2);
	}
	
	if (even == n) {
		cout << n << "\n";
		return 0;
	}
	
	if (c[5] + c[0] == n) {
		cout << n << "\n";
		return 0;
	}
	
	if (c[1] || n != 2) {
		cout << 1 << "\n";
		return 0;
	}
	
	if (n == 2) {
		int a = d[0], b = d[1];
		for(int i=0; i < 20; i++) {
			b = (a+b) % 10;
			
			if (b == 9 || b == 1) {
				cout << 1 << "\n";
				return 0;
			}
		}
		
		a = d[0], b = d[1];
		for(int i=0; i < 20; i++) {
			a = (a+b) % 10;
			
			if (a == 9 || a == 1) {
				cout << 1 << "\n";
				return 0;
			}
		}
		
		cout << 2 << "\n";
		return 0;
	}
	
	// shouldn't happen
	return 1;
}