#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	map<int, vector<int>> idx;
	set<int> s;
	
	for(int i=0; i < n; i++) {
		int x;
		cin >> x;
		
		s.insert(x);
		idx[x].push_back(i+1);
	}
	
	for(auto &it : s) {
		if (it > x)
			continue;
		
		if (s.count(x - it) && x - it != it) {
			cout << idx[it][0] << " " << idx[x - it][0] << endl;
			return 0;
		} else if (x - it == it && idx[it].size() > 1) {
			cout << idx[it][0] << " " << idx[it][1] << endl;
			return 0;
		}
	}
	
	cout << "IMPOSSIBLE" << endl;
}