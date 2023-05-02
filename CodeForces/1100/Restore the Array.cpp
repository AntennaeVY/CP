#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> b(n-1);
		for(auto &bi : b) cin >> bi;
		
		//      3           4           4           5
		
		// max(a1, a2) max(a2, a3) max(a3, a4) max(a4, a5)
		
		// Caso 1: b1 < b2
		// a2 = b1, a3 = b2;
		
		// Caso 2: b1 > b2
		// a1 = b1, a2 = b2;
		
		// Caso 3: b1 == b2
		// a2 = b2;
		
		vector<int> a(n, 0);
		
		if (n == 2)
			a[0] = b[0];
		
		for(int i=1; i < n-1; i++) {
			if (b[i-1] < b[i])
				a[i] = b[i-1], a[i+1] = b[i];
			else if (b[i-1] > b[i]) 
				a[i-1] = b[i-1], a[i] = b[i];
			else
				a[i] = b[i];
		}
		
		for(auto &ai : a) 
			cout << ai << " ";
			
		cout << endl;
	}
}