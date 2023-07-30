#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> d(n);
		for(auto &di : d) cin >> di;
		
		set<long long> present;
		for(auto &di : d) present.insert(di);
		
		sort(d.begin(), d.end());
		
		bool ok = true;
		long long x = 1LL*d[0]*d.back();
		
		for(long long i=2; i*i <= x; i++) {
			if (x % i != 0)
				continue;
				
			if (!present.count(i) || i*i != x && !present.count(x/i))
				ok = false;
				
			present.erase(i);
			present.erase(x/i);
		}
		
		if (!present.empty())
			ok = false;
		
		cout << (ok ? x : -1) << endl;
	}
}