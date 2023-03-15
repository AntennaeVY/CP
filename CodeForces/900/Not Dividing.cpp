#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		if (a[0] == 1)
			a[0]++;
		
		for(int i=1; i < n; i++) {
			if (a[i] == 1)
				a[i]++;
			
			if (a[i] % a[i-1] == 0)
				a[i]++;
		}
		
		for(auto ai : a)
			cout << ai << " ";
			
		cout << endl;
	}
}