#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		while(n) {
			if (n >= k)
				cout << n << " ";
			else
				if (n > m)
					cout << n << " ";
				else
					break;
			
			n--;
		}
		
		for(int i=1; i <= m; i++) 
			cout << i << " ";
			
		cout << endl;
	}
}