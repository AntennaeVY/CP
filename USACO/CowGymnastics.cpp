#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("gymnastics.in");
	ofstream fout("gymnastics.out");
	
	int k, n;
	fin >> k >> n;
	
	vector<map<int, int>> a(k);
	
	for(int i=0; i < k; i++) {
		for(int j=0; j < n; j++) {
			int x;
			fin >> x;
			
			a[i][x] = j;
		}
	}
	
	int ans = 0;
	
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= n; j++) {
			if (i == j) continue;
			
			bool good = true;
			
			for(int p=0; p < k; p++) {				
				if (a[p][i] > a[p][j]) 
					good = false;
			}
			
			if (good)
				ans++;
		}
	}
	
	fout << ans << endl;
}