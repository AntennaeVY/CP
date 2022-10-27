#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a, x(n), y(n);
		
		for(int i=0; i < n; i++) {
			cin >> x[i];
		}
		
		for(int i=0; i < n; i++) {
			cin >> y[i];
		}
				
		for(int i=0; i < n; i++) {
			a.push_back(x[i]+y[i]);
			a.push_back(x[i]-y[i]);
		}
		
		sort(a.begin(), a.end());

		cout << fixed << setprecision(7);
		cout << (a[0] + a.back())/2.0 << endl;
	}
}