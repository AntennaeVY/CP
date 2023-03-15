#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		int i,j;
		for(i=0; i < n; i++) {
			if (a[i] != (i+1))
				break;
		}
		
		for(j=n-1; j >= 0; j--) {
			if (a[j] != (j+1))
				break;
		}
		
		if (i == n) {
			cout << 0 << endl;
			continue;
		}
		
		int needs_one = true;
		
		for(; i < j; i++) {
			if (a[i] == i+1)
				needs_one = false;
		}
		
		cout << (needs_one ? 1 : 2) << endl;
	}
}