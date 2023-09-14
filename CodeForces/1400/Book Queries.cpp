#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	int l=0, r=0;
	map<int, pair<int,int>> cnt;
	map<int, int> idx;
	vector<pair<int, int>> add(q+1);
	
	for(int i=1; i <= q; i++) {
		char t;
		int id;
		
		cin >> t >> id;
		
		if (t == 'L') {
			idx[id] = i;
			cnt[id] = {0, l+r};
			add[i] = make_pair(++l, r); 
		} else if (t == 'R') {
			idx[id] = i;
			cnt[id] = {l+r, 0};
			add[i] = make_pair(l, ++r);
		} else {
			int left = cnt[id].first + l - add[idx[id]].first;
			int right = cnt[id].second + r - add[idx[id]].second;
			
			cout << min(left, right) << endl;
		}
	}
}