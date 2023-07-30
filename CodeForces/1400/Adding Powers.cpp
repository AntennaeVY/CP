#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<long long> v(n);
		
		long long maxima = 0;
		
		for(int i=0; i < n; i++) {
			cin >> v[i];
			maxima = max(maxima, v[i]);
		}
		
		bool can = true;
		long long current = 1;
		while(current < maxima) current *= k;
		
		while(current > 0) {
			sort(v.rbegin(), v.rend());
			map<long long, int> m;
			
			if (v[0] == 0)
				break;
			
			if (v[0] >= current)
				v[0] -= current;
			
			for(int i=0; i < n; i++) {
				m[v[i]]++;
				
				if (m[v[i]] > 1 && v[i] != 0)
					can = false;

			}
			
			current /= k;
		}
		
		for(int i=0; i < n; i++) {
			if (v[i] != 0)
				can = false;
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}