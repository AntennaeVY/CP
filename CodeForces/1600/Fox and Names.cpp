#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<string> a(n);
	for(auto &ai : a) cin >> ai;
	
	map<char, vector<char>> graph;
	map<char, int> in_degree;
	
	bool impossible = false;
	
	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			int l1 = a[i].size();
			int l2 = a[j].size();
			
			for(int k=0; k < min(l1, l2); k++) {
				if (a[i][k] == a[j][k] && k == l2 - 1 && l1 > l2)
					impossible = true;
					
				if (a[i][k] != a[j][k]) {
					graph[a[i][k]].push_back(a[j][k]);
					in_degree[a[j][k]] += 1;
					break;
				}
			}
		}
	}
	
	// Kahn's Algorithm for Topological Sorting
	
	string ans = "";
	queue<char> q;
	
	for(int i=0; i < 26; i++) {
		if (in_degree['a' + i] == 0)
			q.push('a' + i);
	}
	
	while(!q.empty()) {
		char x = q.front();
		q.pop();
		
		ans += x;
		
		for(char y : graph[x]) {
			in_degree[y]--;
			
			if (in_degree[y] == 0)
				q.push(y);
		}
	}
	
	if (ans.size() != 26 || impossible) {
		cout << "Impossible" << endl;
		return 0;
	}
	
	cout << ans << endl;
}