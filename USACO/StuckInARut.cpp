#include<bits/stdc++.h>
using namespace std;

constexpr int INF = 2e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<pair<int,int>> cows(n);
	vector<int> north, east;
	
	for(int i=0; i < n; i++) {
		char t;
		cin >> t;
		
		int x, y;
		cin >> x >> y;
		
		cows[i] = {x, y};
		
		if (t == 'N')
			north.push_back(i);
		else
			east.push_back(i);
	}
	
	sort(north.begin(), north.end(), [&](auto &i, auto &j) { 
		return cows[i].first < cows[j].first;
	});
	
	sort(east.begin(), east.end(), [&](auto &i, auto &j){
		return cows[i].second < cows[j].second;
	});
	
	vector<int> ans(n, INF);
	
	for(int i=0; i < north.size(); i++) {
		for(int j=0; j < east.size(); j++) {	
			int dx = cows[north[i]].first - cows[east[j]].first;
			int dy = cows[east[j]].second - cows[north[i]].second;
				
			if (dx < 0 || dy < 0)
				continue;
				
			if (dx > dy) {
				if (ans[north[i]] < dy)
					continue;
					
				ans[east[j]] = min(ans[east[j]], dx);
			} else if (dx < dy) {
				if (ans[east[j]] < dx)
					continue;
				
				ans[north[i]] = min(ans[north[i]], dy);
			}
		}
	}

	for(int i=0; i < n; i++) {
		cout << (ans[i] == INF ? "Infinity" : to_string(ans[i])) << endl; 
	}
}