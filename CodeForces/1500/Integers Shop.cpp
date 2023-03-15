#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int l=0, r=0;
		
		map<pair<int, int>, int> min_cost_range;
		vector<pair<int, int>> s(n);
		vector<int> c(n);
		
		for(int i=0; i < n; i++) {
			int li, ri;
			cin >> li >> ri >> c[i];
			
			s[i] = {li, ri};
		}
				
		for(int i=0; i < n; i++) {
			if (s[i].second > s[r].second) 
				r = i;
			else if (s[i].second == s[r].second)
				r = (c[i] < c[r] ? i : r);
				
			if (s[i].first < s[l].first)
				l = i;
			else if (s[i].first == s[l].first)
				l = (c[i] < c[l] ? i : l);
	
			pair<int, int> range = {s[l].first, s[r].second};
			
			if (!min_cost_range.count(range))
				min_cost_range[range] = c[l] + c[r];
				
			if (s[i] == range)
				min_cost_range[range] = min(min_cost_range[range], c[i]);
			
			if (s[l].first == s[r].first)
				min_cost_range[range] = min(min_cost_range[range], c[r]);
			
			if (s[l].second == s[r].second)
				min_cost_range[range] = min(min_cost_range[range], c[l]);
		
			min_cost_range[range] = min(min_cost_range[range], c[l] + c[r]);
			
			cout << min_cost_range[range] << endl;
		}
	}
}