#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(int i=0; i < n; i++) {
			cin >> a[i];
		}
		
		int l=0;
		for(int r=0; r < n; r++) {
			while(r-l > 0 && a[l] < r-l+1) 
				l++;
				
			cout << r-l+1 << " ";
		}
		
		cout << endl;
	}
}