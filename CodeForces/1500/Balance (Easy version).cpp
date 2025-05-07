#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	
	map<long long, long long> mp;
	set<long long> s = {0};
	
	while(q--) {
		char t;
		long long x;
		
		cin >> t >> x;
		
		if (t == '+') {
			s.insert(x);
		} else {
			for(long long i = mp[x]; i <= 4e18; i += x) {
				if (!s.count(i)) {
					mp[x] = i;
					cout << i << "\n";
					break;
				}
			}
		}
	}
}