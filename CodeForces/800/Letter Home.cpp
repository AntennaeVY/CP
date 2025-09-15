#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, s;
		cin >> n >> s;
		
		vector<int> x(n);
		for(auto &xi : x) cin >> xi;
		
		x.push_back(s);
		n++;
		
		sort(x.begin(), x.end());
		
		cout << 2*min(s - x[0], x.back() - s) + max(s - x[0], x.back() - s) << "\n";
	}
}