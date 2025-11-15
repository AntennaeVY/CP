#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		
		int msb_a = __builtin_clz(a);
		int msb_b = __builtin_clz(b);
		
		if (msb_b < msb_a) {
			cout << -1 << '\n';
			continue;
		}
		
		vector<int> ans;
		
		int x = 0;
		for(int i=0; i < 31; i++) {
			int bit_a = (1 << i) & a;
			int bit_b = (1 << i) & b;
			
			if (bit_b == bit_a)
				continue;
				
			if (x + bit_a + bit_b > a) {
				ans.push_back(x);
				x = 0;
			}
			
			x += bit_b + bit_a;
		}
		
		if (x > 0)
			ans.push_back(x);
			
		if (a == b) {
			cout << "0\n";
			continue;
		}
		
		cout << ans.size() << "\n";
		for(auto &ansi : ans) {
			cout << ansi << " ";
			assert(ansi <= a);
		}
			
		cout << "\n";
	}
}