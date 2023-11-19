#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> b = a;
		sort(b.rbegin(), b.rend());
		
		for(int i=0; i < n; i++) {
			if (a[i] == b[0])
				cout << a[i] - b[1] << " ";
			else
				cout << a[i] - b[0] << " ";
		}
		
		cout << endl;
	}
}