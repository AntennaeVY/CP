#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n), ia(n), ib(n);
		
		for(int i=0; i < n; i++) {
			cin >> a[i];
			ia[i] = i;	
		}
		
		for(int i=0; i < n; i++) {
			cin >> b[i];
			ib[i] = i;
		}
		
		sort(ia.begin(), ia.end(), [&](int i, int j) {
			return a[i] < a[j];
		});
		
		sort(ib.begin(), ib.end(), [&](int i, int j) {
			return b[i] < b[j];
		});
		
		map<int, int> la, lb;
		
		for(int i=0; i < n; i++) {
			la[ia[i]] = i;
			lb[ib[i]] = i;
		}
		
		vector<bool> ans(n);
		queue<pair<int, int>> q;
		q.push({ia.back(), 0});
		q.push({ib.back(), 1});
		ans[ia.back()] = ans[ib.back()] = true;
		
		while(!q.empty()) {
			auto &[x, j] = q.front();
			q.pop();
			
			if (j == 0)
				for(int i=lb[x]+1; i < n; i++) {
					if (ans[ib[i]])
						break;
						
					ans[ib[i]] = true;
					q.push({ib[i], 1});
				}
			else if (j == 1)
				for(int i=la[x]+1; i < n; i++) {
					if (ans[ia[i]])
						break;
						
					ans[ia[i]] = true;
					q.push({ia[i], 0});
				}
		}
		
		for(auto ansi : ans)
			cout << ansi;
		
		cout << endl;
	}
}