#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> x(n), y(n);
		for(int i=0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		
		int X = x[(n+2)/2 - 1] - x[(n+1)/2 - 1] + 1;
		int Y = y[(n+2)/2 - 1] - y[(n+1)/2 - 1] + 1;
		
		cout << 1LL * X * Y << endl;
	}
}