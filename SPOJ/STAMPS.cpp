#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int _=1; _ <= t; _++) {
		cout << "Scenario #" << _ << ":" << endl;
		
		int x, n;
		cin >> x >> n;
		
		vector<int> f(n);
		for(auto &fi : f) cin >> fi;
		
		sort(f.rbegin(), f.rend());
		
		int sum = 0, ans = 0;
		
		for(int i=0; i < n; i++) {
			if (sum + f[i] >= x) {
				ans = i+1;
				break;
			}
			
			sum += f[i];
		}
		
		if (ans)
			cout << ans << endl << endl;
		else
			cout << "impossible" << endl << endl;
	}
}