#include<bits/stdc++.h>
using namespace std;

int main() {
		int t;
		cin >> t;
		
		while(t--) {
			int n;
			cin >> n;
			
			vector<int> a(n);
			for(auto &it:a) cin >> it;
	
			bool sorted = true;
			
			vector<int> firstParity(2, -1);
			
			for(int i=0; i < n-1; i++) { 
				if (a[i] > a[i+1]) sorted = false;
			
				if (firstParity[a[i]%2] == -1) 
					firstParity[a[i]%2] = a[i];
			}
			
			if (sorted) {
				cout << "Yes" << endl;
				continue;
			}
			
			bool ok = true;

			for(int i=0; i < n; i++) {
				if (a[i] >= firstParity[a[i]%2])
					firstParity[a[i]%2] = a[i];
				else
					ok = false; 
			}
			
			cout << (ok ? "Yes" : "No") << endl;
		}
}