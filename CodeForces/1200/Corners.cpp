#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,m;
		cin >> n >> m;
		
		vector<vector<char>> a(n, vector<char>(m));
		int ones = 0;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> a[i][j];
				
				if (a[i][j] == '1')
					ones++;
			}
		}
		
		if (ones == n*m) {
			cout << ones-2 << endl;
			continue;
		}
		
		if (ones == 0) {
			cout << 0 << endl;
			continue;
		}
		
		bool adjacent = false;
		bool diagonal = false;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				if (a[i][j] != '0')
					continue;
				
				if (i > 0 && j > 0 && a[i-1][j-1] == '0') 
					diagonal = true;
				
				if (i > 0 && j < m-1 && a[i-1][j+1] == '0')
					diagonal = true;
					
				if(i < n-1 && j > 0 && a[i+1][j-1] == '0')
					diagonal = true;
				
				if (i < n-1 && j < m-1 && a[i+1][j+1] == '0')
					diagonal = true;
					
				
				if (j > 0 && a[i][j-1] == '0')
					adjacent = true;
				
				if (j < m-1 && a[i][j+1] == '0')
					adjacent = true;
				
				if (i > 0 && a[i-1][j] == '0')
					adjacent = true;
					
				if (i < n-1 && a[i+1][j] == '0')
					adjacent = true;
			}
		}
		
		if (adjacent || diagonal)
			cout << ones << endl;
		else
			cout << ones - 1 << endl;
	}
}