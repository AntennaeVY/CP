#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a((n*(n-1))/2);
		for(auto &ai : a) cin >> ai;
		
		map<int, int> cnt;
		
		for(auto ai : a)
			cnt[ai]++;
			
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
			
		for(auto pii : cnt) {
			pq.push(pii);
		}
		
		int c = n-1;
		vector<int> ans;
		
		while(!pq.empty()) {
			auto pii = pq.top();
			pq.pop();
			
			ans.push_back(pii.first);
			pii.second -= c;
			
			if (pii.second != 0)
				pq.push(pii);
				
			c--;
		}
		
		if (ans.size() != n)
			ans.push_back(1e9);
		
		for(auto &ansi : ans)
			cout << ansi << " ";
		
		cout << endl;
	}
}