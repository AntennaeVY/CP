#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("div7.in");
	ofstream fout("div7.out");
	
	int N;
	fin >> N;
	
	vector<int> ps(N+1, 0);
	vector<array<int, 2>> rem(7, {N+1, -1});
	
	rem[0][0] = 0;
	
	for(int i=1; i <= N; i++) {
		int id;
		fin >> id;
		
		ps[i] = (ps[i-1] + id) % 7;
		
		rem[ps[i]][0] = min(rem[ps[i]][0], i);
		rem[ps[i]][1] = max(rem[ps[i]][1], i);
	}
	
	int ans = 0;
	
	for(int i=0; i < 7; i++) {
		if (rem[i][1] == -1)
			continue;
		
		ans = max(ans, rem[i][1] - rem[i][0]);
	}
	
	fout << ans << endl;
}