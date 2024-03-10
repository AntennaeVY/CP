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
		
		int last = 0;
		
		sort(a.begin(), a.end());
		
		for(int i=0; i < n; i++) {
			if (a[i] <= i+1)
				last = i+1;
		}
		
		cout << last + 1 << endl;
	}
}