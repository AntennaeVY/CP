#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<string> names(n);
	vector<int> scores(n);
	vector<vector<int>> positions(m+1, vector<int>());
	
	for(int i=0; i < n; i++) {
		int team;	
			
		cin >> names[i];
		cin >> team;
		cin >> scores[i];
		
		positions[team].push_back(i);
	}
	
	for(int i=1; i <= m; i++) {
		sort(positions[i].begin(), positions[i].end(), [&](const int &a, const int &b){
			return scores[a] > scores[b];
		});
		
		
		if (positions[i].size() > 2 && scores[positions[i][1]] == scores[positions[i][2]])
			cout << "?" << endl;
		else
			cout << names[positions[i][0]] << " " << names[positions[i][1]] << endl;
	}
}