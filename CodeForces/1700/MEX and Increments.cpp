#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, int> cnt;
		vector<int> a(n);
		for(int i=0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		
		sort(a.begin(), a.end());
		
		vector<long long> ans(n+1, -1);
		ans[0] = cnt[0];

		stack<int> s;

		for(int i=1; i <= n; i++) {
			ans[i] = ans[i-1] - cnt[i-1] + cnt[i];
			
			for(int j=1; j < cnt[i-1]; j++)
				s.push(i-1);
				
			if (cnt[i-1])
				continue;
				
			if (s.empty()) {
				ans[i] = -1;
				break;
			}
			
			ans[i] +=  i - 1 - s.top();
			s.pop();
		}
		
		for(int i=0; i <= n; i++)
			cout << ans[i] << " ";
			
		cout << endl;
	}
}