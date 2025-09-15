#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> p(n);
		for(auto &pi : p) cin >> pi;
		
		for(int i=0; i < n; i++)
			cout << (n+1 - p[i]) << " ";
		cout << "\n";
	}
}