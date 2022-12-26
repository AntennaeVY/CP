#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		
		cout << n << endl;
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			
			long long add = (1 << (__lg(a[i]) + 1)) - a[i];
			
			cout << i+1 << " " << add << endl;
 		}
	}
}