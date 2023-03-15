#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<vector<int>> a(n, vector<int>(n-1));
		for(int i=0; i < n; i++) {
			for(int j=0; j < n-1; j++) {
				cin >> a[i][j];
			}
		}
		
		map<int, int> m;
		
		for(int i=0; i < 3; i++) {
			m[a[i][0]]++;
		}
		
		int first = (m[a[0][0]] > m[a[1][0]] ? a[0][0] : a[1][0]);
		
		cout << first << " ";
		
		for(int i=0; i < n; i++) {
			if (a[i][0] != first) {
				for(int j=0; j < n-1; j++) {
					cout << a[i][j] << " ";
				}
				
				break;
			}
		}
		
		cout << endl;
	}
}