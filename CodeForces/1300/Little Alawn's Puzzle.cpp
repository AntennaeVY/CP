#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int binPowMod(int base, int exp, const int mod) {
	if (exp == 0) return 1;
	
	if (exp & 1) {
		return (1LL * base * binPowMod(base, exp-1, mod))%mod;
	} else {
		return (1LL * binPowMod(base, exp/2, mod) * binPowMod(base, exp/2, mod))%mod;
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int cycles = 0;
		map<int,int> edges;
		map<int,bool> visited;
		vector<int> nodes(n);
		
		for(auto &ai:nodes) cin >> ai;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			edges[nodes[i]] = x;
		}
		
		for(int i=0; i < n; i++) {
			int current = nodes[i];
			
			if (visited[current]) continue;
			
			while(!visited[current]) {
				visited[current] = true;
				current = edges[current];
			} 
			
			cycles++;
		}
		
		cout << binPowMod(2, cycles, MOD) << endl;
	}
}