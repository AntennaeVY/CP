#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("planting.in");
	ofstream fout("planting.out");
	
	int n;
	fin >> n;
	
	int ans = 0;
	map<int, int> deg;
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		fin >> u >> v;
		
		ans = max(ans, max(++deg[u], ++deg[v]));
	}
	
	fout << ans + 1 << endl;
}