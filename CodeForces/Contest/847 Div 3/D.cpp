#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a;
		map<int, int> m;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;

			a.push_back(x);
				
			m[x]++;	
		}
		
		sort(a.rbegin(), a.rend());
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			if (m[a[i] - 1] == 0)
				ans++;
			else
				m[a[i] - 1]--;
		}
		
		cout << ans << endl;
	}
}