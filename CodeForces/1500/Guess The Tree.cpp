#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> p(n+1, -1);
		
		for(int i=1; i < n; i++) {
			int m = n;
			
			do {
				cout << "? " << i << " " << m << endl;
				cin >> m;
				
				if (m != i)
					p[i] = m;
					
				if (m == i && p[i] == -1)
					p[i] = n;
			} while(m != i);
		}
		
		cout << "! ";
		
		for(int i=1; i < n; i++) {
			cout << i << " " << p[i] << " ";
		}
		
		cout << endl;
	}
}