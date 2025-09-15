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
		
		vector<int> p(n);
		iota(p.begin(), p.end(), 1);
		
		int sum = 0;
		for(int i=1; i <= n; i++) {
			sum += (2*i - 1) * (i);
		}
		
		cout << sum << " " << 2*n - 1<< "\n";
		cout << 1 << " " << n << " ";
		for(auto &pi : p)
			cout << pi << " ";
		cout << "\n";
		
		for(int i=n-1; i >= 1; i--) {
			cout << 1 << " " << i << " "; 
			for(auto &pi : p)
				cout << pi << " ";
			cout << "\n";
			
			cout << 2 << " " << i << " ";
			for(auto &pi : p)
				cout << pi << " ";
			cout << "\n";
		}
	}
}