#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		
		map<char, pair<int, int>> m = {
			{'L', {-1, 0}},
			{'R', {1, 0}},
			{'U', {0, 1}},
			{'D', {0, -1}}
		};
		
		int x = 0, y = 0;
		
		vector<pair<int, int>> pref(n+1, {0,0});
		
		for(int i=0; i < n; i++) {
			pref[i+1].first = pref[i].first + m[s[i]].first;
			pref[i+1].second = pref[i].second + m[s[i]].second;
		}
		
		for(int i=0; i < n; i++) {
			pair<int, int> p, pos;
			
			p = pref[i+1];
			pos = {0, 0};
			
			for(int j=0; j < n; j++) {
				pair<int, int> new_pos = pos;
				
				new_pos.first += m[s[j]].first;
				new_pos.second += m[s[j]].second;
				
				if (new_pos.first != p.first || new_pos.second != p.second) {
					pos = new_pos;
				}
			}
			
			if (pos.first == 0 && pos.second == 0) {
				x = p.first;
				y = p.second;
			}
		}
		
		cout << x << " " << y << endl;
	}
}