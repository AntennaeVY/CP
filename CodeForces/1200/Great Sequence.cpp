#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		int ans = 0;
		vector<int> a(n);
		queue<int> q;
		map<int, int> freq;
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			
			freq[a[i]]++;
		}
		
		sort(a.rbegin(), a.rend());
		
		for(int i=0; i < n; i++) {
			if (!q.empty() && q.front() == a[i]) {
				q.pop();
				continue;
			}
			
			if (a[i]%x == 0 && freq[a[i]/x] > 0) {
				q.push(a[i]/x);
				freq[a[i]]--;
				freq[a[i]/x]--;
				continue;
			}
			
			ans++;
		}
		
		cout << ans << endl;
	}
}