#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int sum = 0;
		set<pair<int,int>> s;
		
		for(int i=1; i <= n; i++) {
			int x;
			cin >> x;
			
			if (x != 0)
				s.insert({x, i});
				
			sum += x;
		}
		
		int ans = 0;
		vector<pair<int,int>> ops;
					
		while(s.size() >= 2) {
			auto p1 = prev(s.end());
			auto p2 = prev(p1);
			
			auto val1 = *p1;
			auto val2 = *p2;
			
			s.erase(p1), s.erase(p2);
			
			val1.first -= 1;
			val2.first -= 1;
			
			ops.push_back({val1.second, val2.second});
			ans++;
			
			if (val1.first != 0)
				s.insert(val1);
			
			if (val2.first != 0)
				s.insert(val2);
		}
		
		cout << ans << endl;
		
		for(auto op : ops) {
			cout << op.first << " " << op.second << endl;
		}
	}
}