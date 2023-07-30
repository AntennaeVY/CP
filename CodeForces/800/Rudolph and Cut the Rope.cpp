#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 0;
		vector<int> a(n), b(n);
		
		for(int i=0; i < n; i++) {
			cin >> a[i] >> b[i];
			
			if (b[i] < a[i])
				ans++;
		}
		
		cout << ans << endl;
	}
}