#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> T(n), D(n), CT(n+1, 0), CD(n+1, 0);
		
		for(int i=0; i < n; i++) {
			cin >> T[i] >> D[i];
			CT[T[i]]++, CD[D[i]]++;
		}
		
		long long ans = 1LL*n*(n-1)*(n-2)/6;
		
		for(int i=0; i < n; i++) {
			ans -= 1LL*(CT[T[i]] - 1)*(CD[D[i]] - 1);
		}
		
		cout << ans << endl;
	}
}