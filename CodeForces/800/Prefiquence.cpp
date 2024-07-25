#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		string s1, s2;
		cin >> s1 >> s2;
		
		int i=0, j=0;
		
		while(i < n && j < m) {
			while(j < m && s2[j] != s1[i])
				j++;
				
			if (j < m)
				i++;
			
			j++;
		}
		
		cout << i << endl;
	}
	
}