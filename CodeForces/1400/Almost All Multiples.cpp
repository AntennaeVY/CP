#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a(n, 0);
		map<int, bool> used;
		
		a[0] = x;
		a[n-1] = 1;
		
		used[x] = true;
		used[1] = true;
		
		bool can = true;
		
		for(int i=1; i < n-1; i++) {
			int j = i+1;
			
			while(used[j]) {
				j += j;
			}
			
			a[i] = j;
			used[j] = true;
				
			if (a[i] > n)
				can = false;
		}
		
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		
		for(int i=0; i < n; i++) {
			cout << a[i] << " ";
		}
		
		cout << endl;
	}
}