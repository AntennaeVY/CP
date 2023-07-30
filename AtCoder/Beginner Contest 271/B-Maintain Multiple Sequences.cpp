#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector<vector<int>> sequences;
	
	for(int i{}; i < n; i++) {
		int x;
		cin >> x;
		
		vector<int> a(x);
		for(auto &it:a) cin >> it;
		
		sequences.push_back(a);
	}
	
	for(int i{}; i < q; i++) {
		int s,t;
		cin >> s >> t;
		
		cout << sequences[s-1][t-1] << endl;
	}
}