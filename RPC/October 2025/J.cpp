#include<bits/stdc++.h>
using namespace std;

using min_heap = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	min_heap start, end;
	set<int> s;
	
	for(int i=0; i < n; i++) {
		int x;
		cin >> x;
		
		for(int j=0; j < x; j++) {
			int s, e;
			cin >> s >> e;
			
			start.push({s, i});
			end.push({e, i});
		}

		s.insert(i);
	}
	
	int ans = 0;
	
	for(int i=1; i <= m; i++) {
		while(!end.empty() && end.top().first < i) {
			s.insert(end.top().second);
			end.pop();
		}
		
		while(!start.empty() && start.top().first == i) {
			s.erase(start.top().second);
			start.pop();
		}
		
		ans += (s.size() >= 3);
	}
	
	cout << ans << '\n';
}