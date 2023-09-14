#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	int a[256][256], curr = 4;
	
	for(int i=0; i < 256; i+=2) {
		for(int j=0; j < 256; j+=2) {
			a[i][j] = curr;
			a[i][j+1] = curr + 1;
			a[i+1][j] = curr + 2;
			a[i+1][j+1] = curr + 3;
			
			curr += 4;
		}
	}
	
	while(t--) {
		int n, m;
		cin >> n >> m;	
		
		cout << n * m << endl;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cout << a[i][j] << " ";
			}
			
			cout << endl;
		}
	}
}