#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
			
		vector<int> a(n);
		int odd = 0, even = 0;
			
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (x % 2)
				odd++;
			else
				even++;
				
			a[i] = x;	
		}
		
		sort(a.begin(), a.end());
		
		if (odd % 2 == 0 && even % 2 == 0)
			cout << "YES" << endl;
		else {
			bool ok = false;
			
			for(int i=0; i < n; i++) {
				if (i > 0 && a[i] - a[i-1] == 1)
					ok = true;
			}
			
			cout << (ok ? "YES" : "NO") << endl;
		}
	}
}