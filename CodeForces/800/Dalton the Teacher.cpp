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
		
		int cnt = 0;
		
		for(int i=0; i < n; i++) {
			if (a[i] == i+1)
				cnt++;
		}
		
		cout << (cnt+1)/2 << endl;
	}
}