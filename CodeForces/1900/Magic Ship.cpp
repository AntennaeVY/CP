#include<bits/stdc++.h>
using namespace std;

int main() {
	int x, y, u, v;
	cin >> x >> y >> u >> v;
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	vector<pair<int, int>> m(n+1, pair<int, int>(0, 0));
	
	for(int i=0; i < n; i++) {
		auto curr = m[i];
		
		if (s[i] == 'U')
			curr.second += 1;
		if (s[i] == 'D')
			curr.second -= 1;
		if (s[i] == 'R')
			curr.first += 1;
		if (s[i] == 'L')
			curr.first -= 1;
			
		m[i+1] = curr;
	}
	
	long long l=-1, r=1e18;
	
	while(l+1 < r) {
		long long mid = l + (r-l)/2;
		
		long long X = mid/n * m[n].first + m[mid % n].first;
		long long Y = mid/n * m[n].second + m[mid % n].second;
		
		long long needX = abs(X - (u - x));
		long long needY = abs(Y - (v - y));
		
		if (needX + needY <= mid)
			r = mid;
		else
			l = mid;
	}
	
	if (r == 1e18)
		cout << -1 << endl;
	else
		cout << r << endl;
}