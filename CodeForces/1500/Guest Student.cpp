#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int k;
		cin >> k;
		
		vector<int> a(7);
		for(auto &ai:a) cin >> ai;
		
		int x = count(a.begin(), a.end(), 1);			
		int weeks = max(0, k / x - 1), ans = 7e8 + 1;
		
		for(int i=0; i < 7; i++) {
			if (a[i] == 0)
				continue;
				
			int p = 0, d = 0;
			
			for(int j=i; true; j++) {
				if (weeks*x + p == k)
					break;
					
				p += a[j % 7];
				d++;
			}
			
			ans = min(ans, weeks*7 + d);
		}	
		
		cout << ans << endl;
	}
}