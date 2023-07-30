#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("shell.in");
	ofstream fout("shell.out");
	
	int n;
	fin >> n;
	
	int result = 0;
	array<int, 3> state = {1,2,3}, ans = {0,0,0};

	for(int i=0; i < n; i++) {
		int x, y, z;
		fin >> x >> y >> z;
		
		for(int j=0; j < 3; j++) {
			if (state[j] == x) {
				state[j] = y;
			} else if (state[j] == y) {
				state[j] = x;
			}
			
			if (z == state[j])
				ans[j]++;
		
			result = max(result, ans[j]);
		}
	}
	
	fout << result << endl;
}