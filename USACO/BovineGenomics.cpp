#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");
	
	int n,m;
	fin >> n >> m;
	
	vector<string> bad(n), good(n);
	
	for(int i=0; i < n; i++) {
		fin >> bad[i];
	}
	
	for(int i=0; i < n; i++) {
		fin >> good[i];
	}
	
	vector<set<int>> bad_sets(m), good_sets(m);
	vector<vector<int>> intersections(m, vector<int>());
	
	for(int j=0; j < m; j++) {
		for(int i=0; i < n; i++) {
			bad_sets[j].insert(bad[i][j]);
		}
	}
	
	for(int j=0; j < m; j++) {
		for(int i=0; i < n; i++) {
			good_sets[j].insert(good[i][j]);
		}
	}
	
	int ans = 0;
	
	for(int j=0; j < m; j++) {
		set_intersection(
				bad_sets[j].begin(), bad_sets[j].end(),
				good_sets[j].begin(), good_sets[j].end(),
				back_inserter(intersections[j])
		);
		
		ans += intersections[j].empty();
	}
	
	fout << ans << endl;
}