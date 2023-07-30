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
		
		map<int, bool> seen;
		map<int, vector<int>> gifters;
		
		set<int> present;
		stack<int> missing;
		
		for(int i=0; i < n; i++) {
			present.insert(a[i]);
			
			gifters[a[i]].push_back(i+1);
		}
		
		for(int i=1; i <= n; i++) {
			if (present.count(i) == 0)
			 	missing.push(i);
		}
		
		vector<int> ans(n);
		
		for(int i=0; i < n; i++) {
			if (seen[a[i]]) {
				ans[i] = missing.top();
				missing.pop();
			} else {
				ans[i] = a[i];
				seen[a[i]] = true;
			}
		}
		
		for(int i=0; i < n; i++) {
			if (i+1 == ans[i]) {
				swap(ans[i], ans[gifters[a[i]][0] - 1]);
			}
		}
		
		cout << present.size() << endl;
		
		for(auto ansi : ans)
			cout << ansi << " ";
			
		cout << endl;
	}
}