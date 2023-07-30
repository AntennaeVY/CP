#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("speeding.in");
	ofstream fout("speeding.out");
	
	int n, m;
	fin >> n >> m;
	
	vector<int> limit(101, 0), bessie(101, 0);
	int total_miles = 0;
	
	for(int i=0; i < n; i++) {
		int miles, speed;
		fin >> miles >> speed;
		
		for(int j=total_miles+1; j <= total_miles+miles; j++) {
			limit[j] = speed;
		}
		
		total_miles += miles;
	}
	
	total_miles=0;
	
	for(int i=0; i < m; i++) {
		int miles, speed;
		fin >> miles >> speed;
		
		for(int j=total_miles+1; j <= total_miles+miles; j++) {
			bessie[j] = speed;
		}
		
		total_miles += miles;
	}
	
	int ans = 0;
	
	for(int i=1; i <= 100; i++) {
		ans = max(ans, bessie[i] - limit[i]);
	}
	
	fout << ans << endl;
}
