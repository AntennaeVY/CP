#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(500, 1e9);
		
		for(int i=0; i < n; i++) {
			int d, s;
			cin >> d >> s;
			
			a[d] = min(a[d], s);
		}
		
		int dest = 500;
		
		for(int i=1; i < 500; i++) {
			if (dest == i)
				break;
		
			dest = min(dest, i + (a[i]+1)/2 - 1);
		}
		
		cout << dest << endl;
	}
}