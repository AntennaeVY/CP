#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(m);
		for(auto &ai : a) cin >> ai;
		
		int inv = 0;
		for(int i=1; i < m; i++) {
			if (a[i] - a[i-1] <= 0)
				inv++;
		}
		
		if (inv > 0) {
			cout << "1\n";
			continue;
		}
		
		cout << n - a.back() + 1 << "\n";
	}
}